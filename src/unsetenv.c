/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** unsetenv
*/

#include "my.h"

static char **rm_line_env(t_shell *shell, int e)
{
    int i = 0;
    int j = 0;
    int find = check_line_env(shell, shell->tab[e]);
    char **new_env = malloc(sizeof(char *) * (len_env(shell->env) + 1));

    if (!new_env)
        return (NULL);
    for (; shell->env[i] != NULL; i++) {
        if (i == find && shell->env[i + 1] != NULL)
            i++;
        else if (i == find && shell->env[i + 1] == NULL) {
            new_env[j] = NULL;
            return (new_env);
        }
        if (shell->env[i] != NULL)
            new_env[j] = my_strdup(shell->env[i]);
        j++;
    }
    return (new_env);
}

void my_unsetenv(t_shell *shell)
{
    if (shell->tab[1] == NULL) {
        my_putstr_error(shell->tab[0]);
        my_putstr_error(": Too few arguments.\n");
    } else {
        for (int i = 1; shell->tab[i] != NULL; i++)
            shell->env = rm_line_env(shell, i);
    }
}
