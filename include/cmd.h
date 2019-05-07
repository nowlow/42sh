/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** cmd
*/

#ifndef CMD_H_
#define CMD_H_

#include "shell.h"

int argc_count(char *str);

int arg_size(char *str);

char **build_argv(char *str, int argc);

cmd_t *my_array_to_cmd(char *str);

cmd_t *get_cmds(int argc, char **argv);

cmd_t *reverse_cmd_list(cmd_t *list);

void cmd_destroy(cmd_t *cmd);

#endif /* !CMD_H_ */