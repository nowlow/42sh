/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** exec_it
*/

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include "shell.h"

int exec_it(s_command *cmd, shell_t *shell)
{
    int ret = 0;
    int fk = 0;
    int child = 1;

    if (cmd->next && cmd->next_link == 1)
        pipe(cmd->next->pipe);
    fk = fork();
    if (cmd->next && cmd->next_link == 1)
        cmd->next->parent = fk;
    if (fk == 0) {
        ret = exe(cmd, shell);
        if (ret == -1)
            ret = exec_from_path(cmd, shell);
    } else {
        wait(&child);
    }
    ret = child_error_handle(child, shell);
    return ret;
}