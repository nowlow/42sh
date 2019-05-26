/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** alias
*/

#include <stdio.h>
#include "shell.h"
#include "parser/parser.h"

void print_aliases(alias_t **aliases)
{
    for (int i = 0; aliases && aliases[i]; i++)
        printf("%s\t%s\n", aliases[i]->alias, aliases[i]->command);
}

int alias(s_command *cmd, shell_t *shell)
{
    alias_t *alias;

    if (cmd->argc == 1)
        print_aliases(shell->aliases);
    if (cmd->argc != 3)
        return 0;
    alias = alias_create(cmd->argv[1], cmd->argv[2]);
    shell->aliases = add_alias(alias, shell->aliases);
    return 0;
}