/*
** EPITECH PROJECT, 2019
** aliases
** File description:
** command_is_alias
*/

#include "aliases.h"
#include "utils.h"
#include <string.h>

alias_t *get_alias(char *command, alias_t **aliases)
{
    size_t command_len = 0;

    for (int i = 0; aliases[i]; i++) {
        command_len = strlen(aliases[i]->alias);
        if (strncmp(command, aliases[i]->alias, command_len) == 0 &&
            IS_SPACE(command[command_len]))
                return aliases[i];
    }
    return NULL;
}