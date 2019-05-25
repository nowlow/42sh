/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** exec
*/

#ifndef EXEC_H_
#define EXEC_H_

#include "../parser/parser.h"

typedef struct exec exec_t;

struct exec {
    int fds[2];
    int ret;
};

int exec_line(char *line);
int exec_path(s_element *node, exec_t *exec);
int execwb(s_command *command);
int get_builtin_cmd(char **argv);

#endif /* !EXEC_H_ */