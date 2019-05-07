/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** my_putchar
*/

#include "my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_puterror(char c)
{
    write(2, &c, 1);
}
