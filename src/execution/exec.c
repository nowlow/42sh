/*
** EPITECH PROJECT, 2019
** exec
** File description:
** exec
*/

#include <stdio.h>

#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include "exec/exec.h"

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

void close_pipe(exec_t *exec, int is_left, int *fds, int op)
{
    if (op == TYPE_PIPE && !is_left) {
        close(exec->fds[1]);
        close(exec->fds[0]);
    }
    exec->fds[0] = fds[0];
    exec->fds[1] = fds[1];
}

int execute_command(s_element *node, exec_t *exec, int op, int is_left)
{
    int fds[2] = {0, 0};
    pid_t pid;
    int ret;

    if (op == TYPE_PIPE && is_left)
        pipe(fds);
    pid = fork();
    if (pid == 0) {
        if (op == TYPE_PIPE) {
            init_pipe(exec, is_left, fds);
        }
        exec_path(node);
    } else {
        if (!is_left && !exec->fds[0])
            close(fds[0]);
        if (exec->fds[0])
            close(exec->fds[1]);
        wait(&ret);
    }
    close_pipe(exec, is_left, fds, op);
    return ret % 255;
}

int recursive_exec(s_element *node, exec_t *exec, int op, int is_left)
{
    int left = 0;
    int right = 0;

    if (node->type == TYPE_OPERATOR) {
        left = recursive_exec(node->data.operator->a, exec,
            node->data.operator->operator_type, 1);
        right = recursive_exec(node->data.operator->b, exec,
            node->data.operator->operator_type, 0);
    } else
        exec->ret = execute_command(node, exec, op, is_left);
    return 0;
}

int exec_line(char *line)
{
    s_element *command = parse(line);
    exec_t exec = {{0, 0}, 0};

    recursive_exec(command, &exec, 0, 1);
    return exec.ret;
}