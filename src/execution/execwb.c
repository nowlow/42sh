/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** execwb
*/

#include <unistd.h>
#include <stdio.h>
#include "parser/parser.h"
#include "builtin.h"

int get_builtin_cmd(char **argv)
{
    if (!argv)
        return -1;
    for (int i = 0; commands[i]; i++) {
        if (my_strcmp(commands[i], argv[0]) == 0)
            return i;
    }
    return -1;
}

int execwb(s_command *comd, shell_t *shell)
{
    int cmd = get_builtin_cmd(comd->argv);

    if (cmd == -1)
        return 1;
    cmd = exec[cmd](comd, shell);
    return cmd;
}