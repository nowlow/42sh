/*
** EPITECH PROJECT, 2018
** minishell1
** File description:
** pasrsing env
*/

#include "my.h"

static int check_carac(char c)
{
    if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') ||
        (c >= 'A' && c <= 'Z') || c == '/' || c == '.' || c == '_')
        return (1);
    return (0);
}

static int len_word(char const *str)
{
    int cpt = 0;

    for (int i = 0; str[i] != '\0'; i++)
        if (check_carac(str[i]) == 0 && str[i] != '\0')
            cpt = cpt + 1;
    return (cpt);
}

static int check_first_word(char const *str, int i)
{
    while (str[i] != '\0' && check_carac(str[i]) == 0)
        i = i + 1;
    return (i);
}

char **parsing_env(char const *str)
{
    int a = 0;
    int b = 0;
    int i = 0;
    char **tab = malloc(sizeof(char *) * (len_word(str)));

    for (i = check_first_word(str, i); str[i] != '\0';) {
        b = 0;
        tab[a] = malloc(sizeof(char) * (my_strlen(str)));
        while (check_carac(str[i]) == 1 && str[i] != '\0') {
            tab[a][b] = str[i];
            i = i + 1;
            b = b + 1;
        }
        while (check_carac(str[i]) == 0 && str[i] != '\0')
            i = i + 1;
        tab[a][b] = '\0';
        a = a + 1;
    }
    tab[a] = NULL;
    return (tab);
}
