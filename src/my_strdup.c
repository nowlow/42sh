/*
** EPITECH PROJECT, 2018
** Day 08
** File description:
** strdup
*/

#include "my.h"

char *my_strdup(char const *src)
{
    char *string = malloc(sizeof(char) * (my_strlen(src) + 1));

    if (string == NULL)
        return (NULL);
    for (int i = 0; src[i] != '\0'; i++) {
        string[i] = src[i];
        string[i + 1] = '\0';
    }
    return (string);
}
