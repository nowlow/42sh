/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** exec
*/

#ifndef EXEC_H_
#define EXEC_H_

#include "../parser/parser.h"
#include "../shell.h"

typedef struct exec exec_t;

struct exec {
    int fds[2];
    int ret;
    s_element *op;
    int op_type;
};

int recursive_exec(s_element *node, exec_t *exec, shell_t *shell, int is_left);
int exec_line(char *line, shell_t *shell);
int exec_path(s_element *node, exec_t *exec);
int execwb(s_command *command, shell_t *shell);
int get_builtin_cmd(char **argv);
int child_error_handle(int child, shell_t *shell);
void end_before_wait(exec_t *exec, s_element *node, int inf[3], shell_t *shell);
void close_pipe(exec_t *exec, int is_left, int *fds);

#endif /* !EXEC_H_ */