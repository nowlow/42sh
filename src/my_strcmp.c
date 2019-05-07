/*
** EPITECH PROJECT, 2018
** minishell1
** File description:
** strcmp
*/

#include "my.h"

int my_strcmp(char const *s1, char const *s2)
{
    if (s1 == NULL || s2 == NULL)
        return (0);
    for (int i = 0; s1[i] != '\0' || s2[i] != '\0'; i++) {
        if (s1[i] > s2[i])
            return (1);
        if (s2[i] > s1[i])
            return (-1);
    }
    return (0);
}
