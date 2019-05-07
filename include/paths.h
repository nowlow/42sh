/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** paths
*/

#ifndef PATHS_H_
#define PATHS_H_

#include "shell.h"

int path_size(char *path);

int number_of_path(char *path);

char **getpath(env_t *env);

#endif /* !PATHS_H_ */
