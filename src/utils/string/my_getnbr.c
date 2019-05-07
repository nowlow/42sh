/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** my_getnbr
*/

#include "utils.h"

int my_getnbr(char *str)
{
    long int nbr = 0;
    int min = 0;
    int i = 0;

    for (; !IS_NUM(str[i]); i++)
        min += (str[i] == '-') ? 1 : 0;
    str = &str[i];
    if (!str[0])
        return 0;
    for (i = 0; IS_NUM(str[i]); i++) {
        nbr *= 10;
        nbr += str[i] - '0';
    }
    return (int)nbr * ((min % 2) ? -1 : 1);
}