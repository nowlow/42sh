/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** env_actions
*/

#include <stddef.h>
#include "shell.h"

env_t *the_last_of_env(env_t *env)
{
    while (env->next)
        env = env->next;
    return env;
}

void set_in_last(char *elm, env_t *env)
{
    env_t *last = the_last_of_env(env);
    env_t *tmp = env_in_list(elm, NULL);

    last->next = tmp;
}

env_t *get_this_elem(env_t *list, cmd_t *cmd)
{
    int size = my_strlen(cmd->argv[1]);

    do {
        if (my_strncmp(list->content, cmd->argv[1], size) == 0 &&
            list->content[size] == '=') {
            break;
        }
        list = list->next;
    } while (list);
    return list;
}