/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** pwd
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "shell.h"

char *cat_with_path(shell_t *shell, char *arg)
{
    char *with_slash;
    char *with_home;

    with_slash = my_strmerge(my_getenv("HOME", shell->env), "/");
    with_home = my_strmerge(with_slash, arg);
    return with_home;
}

char *change_it(cmd_t *cmd, shell_t *shell)
{
    char *path = "setenv PWD ";
    char buffer[FILENAME_MAX];

    if (cmd->argc == 2) {
        if (my_strcmp(cmd->argv[1], "-")) {
            if (chdir(cmd->argv[1]) == -1) {
                print_dir_error(cmd->argv[1]);
                return NULL;
            }
            path = my_strmerge(path, getcwd(buffer, FILENAME_MAX));
        } else {
            chdir(my_getenv("OLDPWD", shell->env));
            path = my_strmerge(path, my_getenv("OLDPWD", shell->env));
        }
    } else {
        chdir(my_getenv("HOME", shell->env));
        path = my_strmerge(path, my_getenv("HOME", shell->env));
    }
    return path;
}

cmd_t *get_current_pwd(shell_t *shell)
{
    char *path = "setenv OLDPWD ";
    char *old = my_getenv("PWD", shell->env);
    char *old_path;
    cmd_t *old_pwd;
    char buff[FILENAME_MAX];

    if (old)
        old_path = my_strmerge(path, old);
    else {
        old = getcwd(buff, FILENAME_MAX);
        old_path = my_strmerge(path, old);
    }
    old_pwd = my_array_to_cmd(old_path);
    return old_pwd;
}