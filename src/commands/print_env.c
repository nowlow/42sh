/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** print_env
*/

#include <unistd.h>
#include <stdio.h>
#include "shell.h"

int print_env(s_command *cmd, shell_t *shell)
{
    if (cmd->argc == 1) {
        for (int i = 0; __environ[i]; i++) {
            printf("%s\n", __environ[i]);
        }
        return 0;
    }
    write(2, "env: Too many arguments.\n", 26);
    return 1;
}