/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** print_env
*/

#include <unistd.h>
#include "shell.h"

int print_env(cmd_t *cmd, shell_t *shell)
{
    env_t *list = shell->env;

    if (cmd->argc == 1) {
        while (list) {
            write(1, list->content, my_strlen(list->content));
            write(1, "\n", 1);
            list = list->next;
        }
        return 0;
    }
    write(2, "env: Too many arguments.\n", 26);
    return 1;
}