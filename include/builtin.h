/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
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
    NULL
};

const int (*exec[])(cmd_t *, shell_t *) = {
    &change_dir,
    &get_out,
    &print_env,
    &set_env,
    &unset_env,
    &repartition
};

#endif /* !BUILTIN_H_ */