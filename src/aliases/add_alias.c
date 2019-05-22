/*
** EPITECH PROJECT, 2019
** aliases
** File description:
** add_alias
*/

#include <stdlib.h>
#include "aliases.h"
#include <string.h>

size_t alias_array_len(alias_t **array)
{
    size_t size = 0;

    for (; array && array[size]; size++);
    return size;
}

alias_t *alias_create(char *alias, char *command)
{
    alias_t *new = malloc(sizeof(alias_t));

    new->alias = strdup(alias);
    new->command = strdup(command);
    return new;
}

alias_t **add_alias(alias_t *alias, alias_t **aliases)
{
    size_t size = alias_array_len(aliases);

    if (!alias)
        return aliases;
    aliases = (aliases) ?
        realloc(aliases, sizeof(char *) * (size + 2)) :
        malloc(sizeof(char *) * 2);
    aliases[size + 1] = NULL;
    aliases[size] = alias;
    return aliases;
}