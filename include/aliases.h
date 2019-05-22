/*
** EPITECH PROJECT, 2019
** aliases
** File description:
** aliases
*/

#ifndef ALIASES_H_
#define ALIASES_H_

#include <stddef.h>

typedef struct alias alias_t;

struct alias {
    char *alias;
    char *command;
};

size_t alias_array_len(alias_t **array);

alias_t **add_alias(alias_t *alias, alias_t **aliases);

alias_t *get_alias(char *command, alias_t **aliases);

char *alias_handle(char *command, alias_t **aliases);

alias_t *alias_create(char *alias, char *command);

#endif /* !ALIASES_H_ */
