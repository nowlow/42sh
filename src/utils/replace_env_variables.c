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

static int find_env(char *str, char **env)
{
    if (str == NULL || str[0] == '\0')
        return (-1);
    for (int i = 0; env[i] != NULL; i++)
        if (strncmp(str, env[i], strlen(str)) == 0)
            return (i);
    return (-1);
}

static char *cut_env(char **env, char *str)
{
    int i = find_env(str, env);
    int e = 0;
    char *tmp;

    if (i == -1)
        return (NULL);
    tmp = malloc(sizeof(char) * (strlen(env[i]) + 1));
    if (!tmp)
        return (NULL);
    for (int j = strlen(str) + 1; env[i][j] != '\0'; e++, j++) {
        tmp[e] = env[i][j];
        tmp[e + 1] = '\0';
    }
    return (tmp);
}

static int check_maj(char const c)
{
    if (c >= 'A' &&  c <= 'Z')
        return (0);
    return (1);
}

static char *cut_dollar(char *str, int i)
{
    char *tmp = malloc(sizeof(char) * (strlen(str) + 1));

    if (!tmp)
        return (NULL);
    for (int j = 0; str[i] != '\0' && check_maj(str[i]) == 0; j++, i++) {
        tmp[j] = str[i];
        tmp[j + 1] = '\0';
    }
    return (tmp);
}

static char *cut_dollar_and_env(char *str, int i)
{
    char *tmp = malloc(sizeof(char) * (strlen(str) + 1));

    if (!tmp)
        return (NULL);
    while (str[i] != '\0' && check_maj(str[i]) == 0)
        i++;
    for (int j = 0; str[i] != '\0'; i++, j++) {
        tmp[j] = str[i];
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
        str = cut_env(env, str);
        tmp = cut_dollar_and_env(tab[i], j + 1);
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