/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** reparition
*/

#include <stdio.h>
#include "shell.h"

int repartition(s_command *cmd, shell_t *shell)
{
    int ret = 0;

    ret = exec_dividor[cmd->prev_link](cmd, shell);
    return ret;
}