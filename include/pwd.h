/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** pwd
*/

#ifndef PWD_H_
#define PWD_H_

#include "shell.h"

char *cat_with_path(shell_t *shell, char *arg);

char *change_it(cmd_t *cmd, shell_t *shell);

cmd_t *get_current_pwd(shell_t *shell);

#endif /* !PWD_H_ */
