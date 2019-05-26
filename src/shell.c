/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** shell
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include "shell.h"
#include "aliases.h"
#include "exec/exec.h"
#include <string.h>
#include "get_next_line.h"

int pre_exec(shell_t *shell)
{
    char *filename = (getenv("HOME")) ?
        pstrmerge(getenv("HOME"), ".42shrc") : ".42shrc";
    FILE *file = fopen(filename, "r");
    size_t nread;
    size_t len = 0;
    char *line = NULL;
    int ret;

    if (!file)
        return 0;
    while ((nread = getline(&line, &len, file)) != -1 && shell->will_exit != 1) {
        if (line[strlen(line) - 1] == '\n')
            line[strlen(line) - 1] = 0;
        if (line[0] != '#')
            ret = exec_line(line, shell);
    }
    fclose(file);
    return ret;
}

shell_t *shell_init(void)
{
    shell_t *shell = malloc(sizeof(shell_t));
    int ret = 0;

    shell->will_exit = 0;
    shell->aliases = NULL;
    shell->is_a_tty = isatty(0);
    ret = pre_exec(shell);
    if (shell->will_exit)
        exit(ret);
    return shell;
}

void shell_destroy(shell_t *shell)
{
    if (!shell)
        return;
    for (int i = 0; shell && shell->aliases && shell->aliases[i]; i++) {
        free(shell->aliases[i]->alias);
        free(shell->aliases[i]->command);
        free(shell->aliases[i]);
    }
    free(shell);
}