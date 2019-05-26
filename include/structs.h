/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** structs
*/

#ifndef STRUCTS_H_
#define STRUCTS_H_

#include "aliases.h"
#include "prompt/termkey.h"

typedef struct shell shell_t;

struct shell {
    int will_exit;
    alias_t **aliases;
    termios_t *term;
};

#endif /* !STRUCTS_H_ */
