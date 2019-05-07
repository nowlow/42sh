/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** my exit
*/

#include "my.h"

void my_exit(t_shell *shell)
{
    for (int i = 0; shell->tab[i] != NULL; i++)
        free(shell->tab[i]);
    for (int i = 0; shell->env[i] != NULL; i++)
        free(shell->env[i]);
    my_putstr("exit\n");
    exit(0);
}
