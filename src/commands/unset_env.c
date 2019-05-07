/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** unset_env
*/

#include <stddef.h>
#include "shell.h"

int unset_env(cmd_t *cmd, shell_t *shell)
{
    env_t *list = shell->env;
    int size;

    if (cmd->argc < 2)
        return 1;
    for (int i = 1; i < cmd->argc; i++) {
        size = my_strlen(cmd->argv[i]);
        if (my_strncmp(list->content, cmd->argv[i], size) == 0) {
            shell->env = shell->env->next;
            return 0;
        }
        while (list->next) {
            if (my_strncmp(list->next->content, cmd->argv[i], size) == 0)
                break;
            list = list->next;
        }
        if (list->next == NULL)
            return 1;
        list->next = list->next->next;
    }
    return 0;
}