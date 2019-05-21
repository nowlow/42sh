/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** dividers
*/

#ifndef DIVIDERS_H_
#define DIVIDERS_H_

#include "shell.h"

int exec_it(cmd_t *cmd, shell_t *shell);

int pipe_it(cmd_t *cmd, shell_t *shell);

int redirect_it(cmd_t *cmd, shell_t *shell);

int repartition(cmd_t *cmd, shell_t *shell);

#endif /* !DIVIDERS_H_ */
