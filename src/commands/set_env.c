/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** set_env
*/

#include <stddef.h>
#include <stdlib.h>
#include "shell.h"

int set_env(s_command *cmd, shell_t *shell)
{
    char *tmp = NULL;
    int err;
    char *content = (cmd->argc == 3) ? cmd->argv[2] : "";

    if ((err = set_env_error(cmd, shell)) < 1)
        return ((err == -1) ? 1 : 0);
    setenv(cmd->argv[1], content, 1);
    return 0;
}