/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** builtin
*/

#ifndef BUILTIN_H_
#define BUILTIN_H_

#include "shell.h"

const char *commands[] = {
    "cd",
    "exit",
    "env",
    "setenv",
    "unsetenv",
    "whereis",
    "where",
    "alias",
    NULL
};

const int (*exec[])(s_command *, shell_t *) = {
    &change_dir,
    &get_out,
    &print_env,
    &set_env,
    &unset_env,
    &whereis,
    &where,
    &alias,
    NULL
};

#endif /* !BUILTIN_H_ */