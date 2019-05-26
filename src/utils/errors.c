/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** errors
*/

#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include "shell.h"

void env_perror(void)
{
    my_puterr("setenv: Variable name must contain alphanumeric characters.\n");
}

int set_env_error(s_command *cmd, shell_t *shell)
{
    if (cmd->argc < 2) {
        print_env(cmd, shell);
        return 0;
    }
    if (cmd->argv[1][0] != '_' && !IS_LETTER(cmd->argv[1][0])) {
        my_puterr("setenv: Variable name must begin with a letter.\n");
        return -1;
    }
    for (int i = 1; cmd->argv[1][i]; i++) {
        if (cmd->argv[1][i] != '_' &&
            !IS_LETTER(cmd->argv[1][i]) && !IS_NUMBER(cmd->argv[1][i])) {
            env_perror();
            return -1;
        }
    }
    return 1;
}

void print_dir_error(char *dir)
{
    char *str = strerror(errno);

    my_puterr(dir);
    my_puterr(": ");
    my_puterr(str);
    my_puterr(".\n");
}