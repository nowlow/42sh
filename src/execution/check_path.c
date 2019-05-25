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
        if (execve(node->data.command->argv[0], node->data.command->argv,
            __environ) == -1) {
            dprintf(2, "%s: Command not found.\n", node->data.command->argv[0]);
            return 1;
        }
    }
    return 0;
}

int exec_path(s_element *node)
{
    char *path = getenv("PATH");
    char *tmp = strtok(path, ":");

    if (!path)
        path = "/bin/:/usr/bin:/usr/sbin";
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