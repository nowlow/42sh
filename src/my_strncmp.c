/*
** EPITECH PROJECT, 2018
** Day 06
** File description:
** strncmp
*/

#include <unistd.h>

int my_strncmp(char const *s1, char const *s2, int n)
{
    if (s1 == NULL || s2 == NULL)
        return (0);
    for (int i = 0; i < n; i++) {
        if (s1[i] > s2[i])
            return (1);
        if (s2[i] > s1[i])
            return (-1);
    }
    return (0);
}
