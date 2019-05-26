/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** where
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include "shell.h"
#include "parser/parser.h"

int print_where_paths(char *path, char *arg)
{
    char *tmp;
    struct stat infos;
    int ret = 0;

    tmp = strtok(path, ":");
    while (tmp) {
        if (tmp[strlen(tmp) - 1] != '/')
            tmp = strmerge(tmp, "/");
        tmp = strmerge(tmp, arg);
        if (stat(tmp, &infos) >= 0) {
            printf("%s ", tmp);
            ret = 1;
        }
        tmp = strtok(NULL, ":");
    }
    if (ret)
        printf("\b\n");
    free(path);
    return ret;
}

int where(s_command *cmd, shell_t *shell)
{
    char *path = getenv("PATH");
    alias_t *alias;

    if (!path)
        path = my_strdup("/bin/:/usr/bin:/usr/sbin");
    if (cmd->argc == 1) {
        dprintf(2, "whereis: Too few arguments.\n");
        return 1;
    }
    for (int i = 1; cmd->argv[i]; i++) {
        alias = get_alias(cmd->argv[i], shell->aliases);
        if (alias)
            printf("%s: aliased to %s\n", cmd->argv[i], alias->command);
        if (!print_where_paths(strdup(path), cmd->argv[i]) && !alias) {
            dprintf(2, "%s not found\n", cmd->argv[i]);
        }
    }
}