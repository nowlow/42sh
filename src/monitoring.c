/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** monitoring
*/

#include "my.h"

static int check_slash(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == '/')
            return (1);
    return (0);
}

static char *cut_pwd(char *str)
{
    while (check_slash(str) == 1)
        *str++;
    return (str);
}

void monitoring(t_shell *shell)
{
    if (cut_env(shell->env, "USER") != NULL)
        shell->user = cut_env(shell->env, "USER");
    if (cut_env(shell->env, "PWD") != NULL)
        shell->pwd = cut_pwd(cut_env(shell->env, "PWD"));
    my_putstr(CYAN);
    my_putchar('[');
    my_putstr(shell->user);
    my_putchar('@');
    my_putchar(' ');
    my_putstr(shell->pwd);
    my_putstr("]$ ");
    my_putstr(WHITE);
}
