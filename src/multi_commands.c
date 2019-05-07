/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** multi_commands
*/

#include <stdlib.h>
#include <stdio.h>
#include "dividers.h"
#include "shell.h"

int is_arg_dividor(char *arg)
{
    for (int i = 0; dividers[i]; i++) {
        if (my_strncmp(dividers[i], arg, my_strlen(dividers[i])) == 0)
            return i;
    }
    return -1;
}

int get_divider(char *arg)
{
    int ret = 0;

    if (!arg)
        return -1;
    for (int j = 0; arg[j]; j++) {
        if ((ret = is_arg_dividor(&arg[j])) != -1)
            return ret;
    }
    return -1;
}

int cmd_size(char **argv)
{
    int count = 0;

    for (count; argv[count]; ++count) {
        if (argv[count] == NULL)
            return count;
        if (get_divider(argv[count]) != -1)
            return count;
    }
    return count;
}

cmd_t *add_cmd(int argc, char **argv, int link, cmd_t *next)
{
    cmd_t *cmd = malloc(sizeof(cmd_t));

    cmd->argc = argc;
    cmd->argv = malloc(sizeof(char *) * (argc + 1));
    for (int i = 0; i < argc; i++)
        cmd->argv[i] = my_strdup(argv[i]);
    cmd->argv[argc] = NULL;
    cmd->parent = getpid();
    cmd->next_link = link;
    cmd->prev_link = (next) ? next->next_link : 0;
    cmd->next = next;
    return cmd;
}

cmd_t *get_cmds(int argc, char **argv)
{
    cmd_t *cmd = NULL;
    int pos = 0;
    int size = 0;
    int last_pos = 0;
    int link = -1;

    while (argv[pos]) {
        size = cmd_size(&argv[pos]);
        pos += size;
        link = get_divider(argv[pos]);
        cmd = add_cmd(size, &argv[last_pos], link, cmd);
        if (pos < argc)
            ++pos;
        last_pos = pos;
    }
    return reverse_cmd_list(cmd);
}