/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** change_dir
*/

#include "shell.h"
#include <stdio.h>
#include <unistd.h>

void change_it(s_command *cmd, shell_t *shell)
{
    char buffer[FILENAME_MAX];

    if (cmd->argc == 2) {
        if (my_strcmp(cmd->argv[1], "-")) {
            if (chdir(cmd->argv[1]) == -1) {
                print_dir_error(cmd->argv[1]);
                return;
            }
        } else {
            chdir(getenv("OLDPWD"));
        }
    } else {
        chdir(getenv("HOME"));
    }
}

int change_dir(s_command *cmd, shell_t *shell)
{
    int ret = 0;
    s_command *tmp = NULL;
    char buffer[FILENAME_MAX];
    char buff2[FILENAME_MAX];
    char *pwd;
    char *old_pwd = getcwd(buff2, FILENAME_MAX);

    if (cmd->argc > 2)
        return 1;
    if (cmd->argc == 2 && cmd->argv[1][0] == '~') {
        cmd->argv[1] = &cmd->argv[1][1];
        cmd->argv[1] = strmerge(getenv("HOME"), cmd->argv[1]);
    }
    change_it(cmd, shell);
    if (old_pwd) {
        pwd = getcwd(buffer, FILENAME_MAX);
        setenv("PWD", (pwd) ? pwd : "", 1);
        setenv("OLDPWD", (old_pwd) ? old_pwd : "", 1);
    } else
        ret = 1;
    return ret;
}