/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** find_and_len_env
*/

#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int len_env(char *str)
{
    int i = 0;

    if (!str)
        return (-1);
    while (str[i] != '=' && str[i] != '\0')
        i++;
    return (i);
}

int find_env(char *str, char **env)
{
    int len = 0;

    if (str == NULL || str[0] == '\0')
        return (-1);
    for (int i = 0; env[i] != NULL; i++) {
        len = len_env(env[i]);
        if (strncmp(str, env[i], len) == 0)
            return (i);
    }
    return (-1);
}