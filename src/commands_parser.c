/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** cmd
*/

#include <stdlib.h>
#include "shell.h"

int argc_count(char *str)
{
    int count = 1;
    int in_quote = 0;

    for (int i = 0; str[i]; i++) {
        if (!in_quote && ((str[i] == ' ' || str[i] == '\t') &&
            (str[i - 1] != ' ' && str[i - 1] != '\t')) && i != 0)
            count += 1;
        if (!in_quote && str[i] == '"')
            in_quote = 1;
        else if (str[i] == '"')
            in_quote = 0;
    }
    if ((str[my_strlen(str) - 1] == ' ' || str[my_strlen(str) - 1] == '\t')
        && count > 1)
        count -= 1;
    return count;
}

int arg_size(char *str)
{
    char stopper = (str[0] == '"') ? '"' : ' ';
    int i = (stopper == ' ') ? 0 : 1;

    if (stopper == '"')
        for (i; str[i] && str[i] != stopper; i++);
    else
        for (i; str[i] && str[i] != stopper && str[i] != '\t'; i++);
    return i;
}

char **build_argv(char *str, int argc)
{
    char **argv = malloc(sizeof(char *) * (argc + 1));
    char *analyze = NULL;
    int in_quote = 0;
    int size;
    int pos = 0;

    for (pos; str[pos] && (str[pos] == ' ' || str[pos] == '\t'); pos++);
    for (int i = 0; i < argc; i++) {
        analyze = &str[pos];
        size = arg_size(analyze);
        argv[i] = malloc(sizeof(char) * (size + 1));
        for (int y = (analyze[0] != '"') ? 0 : 1; y < size; y ++)
            argv[i][(analyze[0] != '"')? y : y - 1] = analyze[y];
        argv[i][(analyze[0] != '"') ? size : size - 1] = 0;
        pos += size;
        for (pos; str[pos] && (str[pos] == ' ' || str[pos] == '\t'); pos++);
    }
    argv[argc] = NULL;
    return argv;
}

cmd_t *my_array_to_cmd(char *str)
{
    int argc = argc_count(str);
    char **argv = build_argv(str, argc);
    cmd_t *commands = get_cmds(argc, argv);

    for (int i = 0; i < argc; i++)
        free(argv[i]);
    free(argv);
    return commands;
}

void cmd_destroy(cmd_t *cmd)
{
    cmd_t *tmp = NULL;

    while (cmd) {
        for (int i = 0; i < cmd->argc; i++)
            (cmd->argv[i]) ? free(cmd->argv[i]) : NULL;
        free(cmd->argv);
        tmp = cmd->next;
        free(cmd);
        cmd = tmp;
    }
}