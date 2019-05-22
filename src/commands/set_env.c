/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** set_env
*/

#include <stddef.h>
#include <stdlib.h>
#include "shell.h"

int set_env(cmd_t *cmd, shell_t *shell)
{
    env_t *list = shell->env;
    char *tmp = NULL;
    int err;
    char *content = (cmd->argc == 3) ? cmd->argv[2] : "\0";

    if ((err = set_env_error(cmd, shell)) < 1)
        return ((err == -1) ? 1 : 0);
    if (my_getenv(cmd->argv[1], shell->env)) {
        list = get_this_elem(list, cmd);
        free(list->content);
        tmp = my_strmerge(cmd->argv[1], "=");
        list->content = my_strmerge(tmp, content);
    } else {
        tmp = my_strmerge(cmd->argv[1], "=");
        tmp = my_strmerge(tmp, content);
        set_in_last(tmp, list);
    }
    return 0;
}