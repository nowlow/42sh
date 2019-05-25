/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** whereis
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include "shell.h"
#include "parser/parser.h"

void print_paths(char *path, char *arg)
{
    char *tmp;
    struct stat infos;

    tmp = strtok(path, ":");
    while (tmp) {
        if (tmp[strlen(tmp) - 1] != '/')
            tmp = strmerge(tmp, "/");
        tmp = strmerge(tmp, arg);
        if (stat(tmp, &infos) >= 0)
            printf("%s ", tmp);
        tmp = strtok(NULL, ":");
    }
    printf("\b\n");
    free(path);
}

int whereis(s_command *cmd, shell_t *shell)
{
    char *path = getenv("PATH");

    if (!path)
        path = my_strdup("/bin/:/usr/bin:/usr/sbin");
    if (cmd->argc == 1) {
        dprintf(2, "whereis: not enough arguments\n");
        return 1;
    }
    for (int i = 1; cmd->argv[i]; i++) {
        printf("%s: ", cmd->argv[i]);
        print_paths(strdup(path), cmd->argv[i]);
    }
}