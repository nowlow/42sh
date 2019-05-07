/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** copy_env
*/

#include "my.h"

int len_env(char **envp)
{
    int i = 0;

    while (envp[i] != NULL)
        i++;
    return (i);
}

char **copy_env(char **envp)
{
    int i = len_env(envp);
    char **new_env = malloc(sizeof(char *) * (i + 1));

    if (!new_env)
        return (NULL);
    for (i = 0; envp[i] != NULL; i++)
        new_env[i] = my_strdup(envp[i]);
    return (new_env);
}
