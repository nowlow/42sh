/*
** EPITECH PROJECT, 2018
** minishell1
** File description:
** strcat
*/

#include "my.h"

char *my_strcat(char const *dest, char const *src)
{
    char *str = malloc(sizeof(char) * (my_strlen(dest) + my_strlen(src) + 1));
    int len = 0;

    if (!str)
        return (NULL);
    for (; dest[len] != '\0'; len++)
        str[len] = dest[len];
    for (int i = 0; src[i] != '\0'; i++) {
        str[len] = src[i];
        len++;
    }
    str[len] = '\0';
    return (str);
}
