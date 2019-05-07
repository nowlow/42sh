/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** path
*/

#include <stdlib.h>
#include <stddef.h>
#include "shell.h"
#include "utils.h"

int path_size(char *path)
{
    int i = 0;

    for (i; path[i] && path[i] != ':'; i++);
    return i;
}

int number_of_path(char *path)
{
    int count = 1;

    for (int i = 0; path[i]; i++) {
        if (path[i] == ':')
            count++;
    }
    return count;
}

char **getpath(env_t *env)
{
    char *ep = (my_getenv("PATH", env)) ? my_getenv("PATH", env) : BASE_PATH;
    int path_sz = 0;
    int passed = 0;
    int j;
    int i;
    char *current;
    int paths = number_of_path(ep);
    char **path = malloc(sizeof(char *) * (paths + 1));

    for (i = 0; i < paths; i++) {
        current = &ep[passed];
        path_sz = path_size(current);
        path[i] = malloc(sizeof(char) * path_sz + 2);
        for (j = 0; j < path_sz; j++)
            path[i][j] = current[j];
        path[i][j] = '/';
        path[i][j + 1] = 0;
        passed += path_sz + 1;
    }
    path[i] = NULL;
    return path;
}