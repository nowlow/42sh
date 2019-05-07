/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** reparition
*/

#include <stdio.h>
#include "shell.h"

int repartition(cmd_t *cmd, shell_t *shell)
{
    int ret = 0;

    ret = exec_dividor[cmd->prev_link](cmd, shell);
    return ret;
}