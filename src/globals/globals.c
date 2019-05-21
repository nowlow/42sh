/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** dividers
*/

#include "shell.h"

char *dividers[6] = {
    ";", "|", ">", "<", "&&", 0
};

int (*exec_dividor[])(cmd_t *cmd, shell_t *shell) = {
    &exec_it, &exec_it, &redirect_it, &redirect_it, &exec_it, NULL
};