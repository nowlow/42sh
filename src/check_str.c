/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** check_str
*/

#include "my.h"

int check_if_int_in_str(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (!((str[i] >= 'a' && str[i] <= 'z') ||
            (str[i] >= 'A' && str[i] <= 'Z')))
            return (1);
    return (0);
}
