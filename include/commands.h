/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** commands
*/

#ifndef COMMANDS_H_
#define COMMANDS_H_

#include "shell.h"

/// Change program work's directory, set PWD and OLDPWD
int change_dir(cmd_t *cmd, shell_t *shell);

/// Execute a binary from a path
int exec_from_path(cmd_t *cmd, shell_t *shell);

/// Return exit needed
int get_out(cmd_t *cmd, shell_t *shell);

/// Execute a not built-in command
int execmd(cmd_t *cmd, shell_t *shell);

/// Add or set a environnement variable
int set_env(cmd_t *cmd, shell_t *shell);

/// Remove one or more evironnement variable
int unset_env(cmd_t *cmd, shell_t *shell);

/// Print environnement variables
int print_env(cmd_t *cmd, shell_t *shell);

// Execute a command
int exe(cmd_t *cmd, shell_t *shell);

int get_divider(char *arg);

int is_arg_dividor(char *arg);

#endif /* !COMMANDS_H_ */
