/*
** EPITECH PROJECT, 2019
** aliases
** File description:
** alias_handle
*/

#include <stdlib.h>
#include <stddef.h>
#include "aliases.h"
#include "utils.h"
#include <string.h>

char *transform_command(char *command, alias_t *alias)
{
    char *cw_cmd = &command[size_to_next_break(command, " \t")];
    size_t size = ((cw_cmd) ? strlen(cw_cmd) : 0) + strlen(alias->command);
    char *final = malloc(sizeof(char) * (size + 1));

    if (!cw_cmd || !cw_cmd[0])
        return alias->command;
    final = strcpy(final, alias->command);
    final = strcat(final, cw_cmd);
    return final;
}

char *alias_handle(char *command, alias_t **aliases)
{
    alias_t *alias = get_alias(command, aliases);

    if (!alias)
        return command;
    command = transform_command(command, alias);
    return command;
}