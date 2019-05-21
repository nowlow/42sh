/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** change_dir
*/

#include "shell.h"

int change_dir(cmd_t *cmd, shell_t *shell)
{
    int ret = 0;
    char *path;
    cmd_t *old_pwd = get_current_pwd(shell);
    cmd_t *tmp = NULL;

    if (cmd->argc > 2)
        return 1;
    if (cmd->argc == 2 && cmd->argv[1][0] == '~') {
        cmd->argv[1] = &cmd->argv[1][1];
        cmd->argv[1] = my_strmerge(my_getenv("HOME", shell->env), cmd->argv[1]);
    }
    path = change_it(cmd, shell);
    if (path && old_pwd) {
        tmp = my_array_to_cmd(path);
        set_env(tmp, shell);
        cmd_destroy(tmp);
        set_env(old_pwd, shell);
    } else
        ret = 1;
    return ret;
}