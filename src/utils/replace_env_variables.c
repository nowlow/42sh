/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** replace_env_variables
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

static int len_env(char *str)
{
    int i = 0;

    if (!str)
        return (-1);
    while (str && str[i] && str[i] != '=')
        i++;
    return (i);
}

static int find_env(char *str, char **env)
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

static char *cut_env(char **env, char *str)
{
    int i = find_env(str, env);
    int e = 0;
    char *tmp;

    if (i == -1)
        return (NULL);
    tmp = calloc(sizeof(char) * (strlen(env[i]) + 1),
        sizeof(char) * (strlen(env[i]) + 1));
    if (!tmp)
        return (NULL);
    for (int j = len_env(env[i]) + 1; env[i][j] != '\0'; e++, j++) {
        tmp[e] = env[i][j];
    }
    return (tmp);
}

static char *cut_dollar(char *str, int i)
{
    char *tmp = calloc(sizeof(char) * (strlen(str) + 1),
        sizeof(char) * (strlen(str) + 1));

    if (!tmp)
        return (NULL);
    for (int j = 0; str[i] != '\0'; j++, i++) {
        tmp[j] = str[i];
        tmp[j + 1] = '\0';
    }
    return (tmp);
}

static char *cut_dollar_and_env(char *str, char **env)
{
    char *tmp = calloc(sizeof(char) * (strlen(str) + 1),
        sizeof(char) * (strlen(str) + 1));
    int len = find_env(str, env);

    len = len_env(env[len]);
    if (!tmp)
        return (NULL);
    for (int i = 0; i < strlen(str) + 1; i++) {
        tmp[i] = 0;
    }
    for (int j = 0; str[len] != '\0'; len++, j++) {
        tmp[j] = str[len];
        tmp[j + 1] = '\0';
    }
    return (tmp);
}

static char *change_tab(char **tab, int i, int j, char **env)
{
    char *str = NULL;
    char *tmp = NULL;

    if (tab[i][j] == '$') {
        str = cut_dollar(tab[i], j + 1);
        tmp = cut_dollar_and_env(str, env);
        str = cut_env(env, str);
        if (str == NULL || tmp == NULL)
            return (tab[i]);
        tab[i] = strcat(str, tmp);
    }
    return (tab[i]);
}

char **replace_env_vars(char **tab)
{
    char **env = __environ;

    for (int i = 0; tab[i] != NULL; i++)
        for (int j = 0; tab[i][j] != '\0'; j++)
            if (change_tab(tab, i, j, env) == NULL)
                return (NULL);
    return (tab);
}