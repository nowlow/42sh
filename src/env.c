/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** env
*/

#include "my.h"

void my_env(t_shell *shell)
{
    for (int i = 0; shell->env[i] != NULL; i++) {
        my_putstr(shell->env[i]);
        my_putchar('\n');
    }
}
