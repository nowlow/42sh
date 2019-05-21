/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** execmd
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/wait.h>
#include "shell.h"
#include "builtin.h"

int exe(cmd_t *cmd, shell_t *shell)
{
    int ret = 0;
    struct stat info;
    int st = stat(cmd->argv[0], &info);

    if (st == -1)
        return -1;
    if (cmd->prev_link == 1) {
        dup2(cmd->pipe[0], 0);
        close(cmd->pipe[0]);
    }
    if (cmd->next_link >= 1) {
        dup2(cmd->next->pipe[1], 1);
        close(cmd->next->pipe[1]);
    }
    ret = execve(cmd->argv[0], cmd->argv, env_list_to_array(shell->env));
    return ret;
}

int get_cmd(cmd_t *cmd)
{
    if (!cmd)
        return -1;
    for (int i = 0;; i++) {
        if (commands[i] == NULL)
            return i;
        if (my_strcmp(commands[i], cmd->argv[0]) == 0)
            return i;
    }
}

int execmd(cmd_t *cmd, shell_t *shell)
{
    int ret = 0;
    int command = get_cmd(cmd);

    if (cmd) {
        ret = exec[command](cmd, shell);
        if (shell->will_exit)
            return ret;
        ret = execmd(cmd->next, shell);
    }
    return ret;
}