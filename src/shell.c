/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** shell
*/

#include <stdlib.h>
#include "shell.h"

shell_t *shell_init(char *name, char *prompt, char **env)
{
    shell_t *shell = malloc(sizeof(shell_t));

    shell->name = name;
    shell->prompt = prompt;
    shell->will_exit = 0;
    return shell;
}

void shell_destroy(shell_t *shell)
{
    free(shell);
}