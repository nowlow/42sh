/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** basics
*/

#include <unistd.h>
#include <stdio.h>

size_t my_strlen(char const *str)
{
    size_t size = 0;

    for (; str && str[size]; size++);
    return size;
}

void my_putstr(char const *str)
{
    write(1, str, my_strlen(str));
}

void my_puterr(char const *str)
{
    write(2, str, my_strlen(str));
}

int my_strcmp(char const *s1, char const *s2)
{
    if (my_strlen(s1) != my_strlen(s2))
        return -1;
    for (int i = 0; s1[i]; i += 1) {
        if (!(s1[i] == s2[i]))
            return (s1[i] - s2[i]);
    }
    return (0);
}

int my_strncmp(char const *s1, char const *s2, int n)
{
    for (int i = 0; s1[i] && s2[i] && i < n; i += 1) {
        if (!(s1[i] == s2[i]))
            return (s1[i] - s2[i]);
    }
    return 0;
}