/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** setenv
*/

#include "my.h"

static int len_of_tab(t_shell *shell)
{
    int i = 0;

    while (shell->tab[i] != NULL)
        i++;
    return (i);
}

static char **fill_new_env(t_shell *shell, char **new_env, int i, int j)
{
    for (; shell->env[i] != NULL; i++) {
        if (i == j) {
            if (shell->tab[2] != NULL)
                new_env[i] = my_strcat(my_strcat(shell->tab[1], "="),
                                        shell->tab[2]);
            else
                new_env[i] = my_strcat(shell->tab[1], "=");
        } else
            new_env[i] = my_strdup(shell->env[i]);
    }
    new_env[i] = NULL;
    return (new_env);
}

static char **add_line_env(t_shell *shell)
{
    int i = 0;
    int j = check_line_env(shell, shell->tab[1]);
    char **new_env = malloc(sizeof(char *) * (len_env(shell->env) + 2));

    if (!new_env)
        return (NULL);
    if (j == -1) {
        for (; shell->env[i] != NULL; i++)
            new_env[i] = my_strdup(shell->env[i]);
        if (shell->tab[2] != NULL)
            new_env[i] = my_strcat(my_strcat(shell->tab[1], "="),
                                    shell->tab[2]);
        else
            new_env[i] = my_strcat(shell->tab[1], "=");
        i++;
        new_env[i] = NULL;
    } else
        new_env = fill_new_env(shell, new_env, i, j);
    return (new_env);
}

void my_setenv(t_shell *shell)
{
    int i = len_of_tab(shell);

    if (i == 1)
        my_env(shell);
    else if (i > 1 && i <= 3) {
        for (int e = 1; e != i; e++)
            if (check_if_int_in_str(shell->tab[e]) == 1) {
                my_putstr_error(shell->tab[0]);
                my_putstr_error(": Variable name must contain alphanumeric "
                                "characters.\n");
                break;
            }
        shell->env = add_line_env(shell);
    }
    if (i >= 4) {
        my_putstr_error(shell->tab[0]);
        my_putstr_error(": Too many arguments.\n");
    }
}
