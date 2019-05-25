/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** unset_env
*/

#include <stddef.h>
#include "shell.h"

int unset_env(s_command *cmd, shell_t *shell)
{
    int size;

    if (cmd->argc < 2)
        return 1;
    for (int i = 1; i < cmd->argc; i++)
        unsetenv(cmd->argv[i]);
    return 0;
}