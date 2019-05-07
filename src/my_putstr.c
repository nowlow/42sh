/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** my_putstr
*/

#include "my.h"

int my_putstr(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        my_putchar(str[i]);
    return (0);
}

int my_putstr_error(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        my_puterror(str[i]);
    return (0);
}
