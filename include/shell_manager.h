/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** shell_manager
*/

#ifndef SHELL_MANAGER_H_
#define SHELL_MANAGER_H_

#include "shell.h"

shell_t *shell_init(char *name, char *prompt, char **env);

void shell_destroy(shell_t *shell);

int run_shell(shell_t *shell);

#endif /* !SHELL_MANAGER_H_ */
