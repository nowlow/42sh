/*
** EPITECH PROJECT, 2019
** RECURSIVE_PIPES
** File description:
** check_path
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "parser/parser.h"
#include "utils.h"
#include "exec/exec.h"

int is_path(char *arg)
{
    if (!arg)
        return 0;
    if (arg[0] == '/')
        return 1;
    if (arg[0] == '.') {
        if (arg[1] == '.' && arg[2] == '/')
            return 1;
        if (arg[1] == '/')
            return 1;
    }
    return 0;
}

int path_handle(s_element *node)
{
    if (is_path(node->data.command->argv[0])) {
        execve(node->data.command->argv[0], node->data.command->argv,
            __environ);
        dprintf(2, "%s: Command not found.\n", node->data.command->argv[0]);
        return 1;
    }
    return 0;
}

int exec_path(s_element *node, exec_t *exec)
{
    char *path = getenv("PATH");
    char *tmp;

    if (!path)
        path = my_strdup("/bin/:/usr/bin:/usr/sbin");
    tmp = strtok(path, ":");
    if (path_handle(node))
        exit(1);
    while (tmp) {
        if (tmp[strlen(tmp) - 1] != '/')
            tmp = strmerge(tmp, "/");
        tmp = strmerge(tmp, node->data.command->argv[0]);
        execve(tmp, node->data.command->argv, __environ);
        tmp = strtok(NULL, ":");
    }
    dprintf(2, "%s: Command not found.\n", node->data.command->argv[0]);
    exit(1);
}

void end_before_wait(exec_t *exec, s_element *node, int fds[2], shell_t *shell)
{
    int is_left = (node == exec->op->data.operator->a);

    if (exec->op_type == TYPE_PIPE && is_left) {
        close_pipe(exec, is_left, fds);
        recursive_exec(exec->op->data.operator->b, exec, shell, 0);
    }
    if (!is_left && !exec->fds[0])
        close(fds[0]);
    if (exec->fds[0])
        close(exec->fds[1]);
}