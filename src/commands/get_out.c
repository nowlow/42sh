/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** get_out
*/

#include "shell.h"

int get_out(s_command *cmd, shell_t *shell)
{
    if (isatty(0))
        write(1, "exit\n", 5);
    shell->will_exit = 1;
    if (cmd->argc == 1)
        return 0;
    return my_getnbr(cmd->argv[1]);
}