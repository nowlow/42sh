/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** commands
*/

#ifndef COMMANDS_H_
#define COMMANDS_H_

#include "shell.h"
#include "parser/parser.h"

/// Change program work's directory, set PWD and OLDPWD
int change_dir(s_command *cmd, shell_t *shell);

/// Return exit needed
int get_out(s_command *cmd, shell_t *shell);

/// Execute a not built-in command
int execmd(s_command *cmd, shell_t *shell);

/// Add or set a environnement variable
int set_env(s_command *cmd, shell_t *shell);

/// Remove one or more evironnement variable
int unset_env(s_command *cmd, shell_t *shell);

/// Print environnement variables
int print_env(s_command *cmd, shell_t *shell);

#endif /* !COMMANDS_H_ */
