/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** env
*/

#ifndef ENV_H_
#define ENV_H_

#include "shell.h"

env_t *env_in_list(char *var, env_t *next);

env_t *build_env_list(char **envt);

char **env_list_to_array(env_t *env);

char *my_getenv(char *var, env_t *env);

env_t *the_last_of_env(env_t *env);

void set_in_last(char *elm, env_t *env);

env_t *get_this_elem(env_t *list, cmd_t *cmd);

#endif /* !ENV_H_ */
