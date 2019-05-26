/*
** EPITECH PROJECT, 2019
** exec
** File description:
** exec
*/

#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include "utils.h"
#include "shell.h"
#include "exec/exec.h"
#include "exec/redirection.h"
#include "prompt/termkey.h"

void init_pipe(exec_t *exec, int is_left, int *fds)
{
    if (is_left) {
        close(fds[0]);
        dup2(fds[1], STDOUT_FILENO);
    }
    if (!is_left && !exec->fds[0]) {
        close(fds[1]);
        dup2(fds[0], STDIN_FILENO);
    }
    if (exec->fds[0]) {
        close(exec->fds[1]);
        dup2(exec->fds[0], STDIN_FILENO);
    }
}

void close_pipe(exec_t *exec, int is_left, int *fds)
{
    if (exec->op_type == TYPE_PIPE && !is_left) {
        close(exec->fds[1]);
        close(exec->fds[0]);
    }
    exec->fds[0] = fds[0];
    exec->fds[1] = fds[1];
}

int execute_command(s_element *node, exec_t *exec, int is_left, shell_t *shell)
{
    int fds[2] = {0, 0};
    pid_t pid = 0;
    int ret;

    if (exec->op_type == TYPE_PIPE && is_left)
        pipe(fds);
    pid = fork();
    if (pid == 0) {
        if (exec->op_type == TYPE_PIPE)
            init_pipe(exec, is_left, fds);
        else if (node->data.command->redirections[0])
            init_redirection(node);
        node->data.command->argv = replace_env_vars(node->data.command->argv);
        exec_path(node, exec, shell);
    } else {
        end_before_wait(exec, node, (int [3]){fds[0], fds[1], is_left}, shell);
        wait(&ret);
    }
    close_pipe(exec, is_left, fds);
    return ret;
}

int recursive_exec(s_element *node, exec_t *exec, shell_t *shell, int is_left)
{
    int left = 0;
    int right = 0;

    if (node->type == TYPE_OPERATOR) {
        exec->op = node;
        exec->op_type = node->data.operator->operator_type;
        left = recursive_exec(node->data.operator->a, exec, shell, 1);
        if (node->data.operator->operator_type != TYPE_PIPE && 
            (node->data.operator->operator_type != TYPE_OR || left))
            right = recursive_exec(node->data.operator->b, exec, shell, 0);
    } else {
        if (get_builtin_cmd(node->data.command->argv) == -1) {
            exec->ret = execute_command(node, exec, is_left, shell);
            exec->ret = child_error_handle(exec->ret, shell);
        } else
            exec->ret = execwb(node->data.command, shell);
    }
    return exec->ret;
}

int exec_line(char *line, shell_t *shell)
{
    s_element *command = parse(line, shell->aliases);
    exec_t exec = {{0, 0}, 0};

    recursive_exec(command, &exec, shell, 1);
    return exec.ret;
}