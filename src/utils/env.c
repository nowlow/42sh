/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** env
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "shell.h"

env_t *env_in_list(char *var, env_t *next)
{
    env_t *elm = malloc(sizeof(env_t));

    if (!elm)
        return NULL;
    elm->content = my_strdup(var);
    elm->next = next;
    return elm;
}

env_t *build_env_list(char **envt)
{
    env_t *env = NULL;
    int len = double_array_len(envt);

    for (int i = len - 1; i >= 0; i--) {
        env = env_in_list(envt[i], env);
        if (!env)
            return NULL;
    }
    return env;
}

char **env_list_to_array(env_t *env)
{
    env_t *list = env;
    char **array;
    int size = 1;
    int i = 0;

    while (list = list->next)
        size++;
    array = malloc(sizeof(char *) * (size + 1));
    if (!array)
        return NULL;
    list = env;
    for (i; list; i++) {
        array[i] = my_strdup(list->content);
        list = list->next;
    }
    array[i] = NULL;
    return array;
}

char *my_getenv(char *var, env_t *env)
{
    env_t *list = env;
    int size = my_strlen(var);
    char *envar;

    while (list) {
        if (my_strncmp(list->content, var, size) == 0) {
            envar = list->content;
            return &envar[size + 1];
        }
        list = list->next;
    }
    return NULL;
}