/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** exec_from_path
*/

#include <stdlib.h>
#include <stdio.h>
#include "shell.h"

int exec_from_path(cmd_t *cmd, shell_t *shell)
{
    int ret = 0;
    char *b_arg = NULL;
    char **paths = getpath(shell->env);

    for (int i = 0; paths[i]; i++) {
        b_arg = cmd->argv[0];
        cmd->argv[0] = strmerge(paths[i], cmd->argv[0]);
        ret = exe(cmd, shell);
        cmd->argv[0] = b_arg;
        if (ret != -1)
            return ret;
    }
    my_putstr(cmd->argv[0]);
    my_putstr(": Command not found.\n");
    exit(1);
    return -1;
}