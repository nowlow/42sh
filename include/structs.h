/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** structs
*/

#ifndef STRUCTS_H_
#define STRUCTS_H_

#include "aliases.h"

typedef struct shell shell_t;

struct shell {
    int will_exit;
    alias_t **aliases;
    int is_a_tty;
};

#endif /* !STRUCTS_H_ */
