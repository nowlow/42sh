/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** errors
*/

#ifndef ERRORS_H_
#define ERRORS_H_

#include "shell.h"
#include "parser/parser.h"

void env_perror(void);

int set_env_error(s_command *cmd, shell_t *shell);

int child_perror(int child);

int child_error_handle(int child, shell_t *shell);

void print_dir_error(char *dir);

#endif /* !ERRORS_H_ */
