/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** historic
*/

#include "historic.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include "utils.h"
#include <string.h>

void history_write(history_t *history)
{
    char *filename = (getenv("HOME")) ?
        pstrmerge(getenv("HOME"), ".42sh_history") : ".42sh_history";
    int fd = open(filename, O_CREAT | O_WRONLY, 0666);
    FILE *file = fopen(filename, "wr");

    if (file == NULL)
        return;
    for (int i = 0; i < history->size; i++) {
        fprintf(file, "%s\n", history->commands[i]);
    }
    fclose(file);
}

char *load_up(history_t *history)
{
    if (history->pos > 0) {
        history->pos -= 1;
        return history->commands[history->pos];
    } else
        return "";
}

char *load_down(history_t *history)
{
    if (history->pos < history->size - 1) {
        history->pos += 1;
        return history->commands[history->pos];
    } else
        return "";
}

history_t *history_push(char *command, history_t *history)
{
    if (strlen(command) && command[strlen(command) - 1] == '\n')
        command[strlen(command) - 1] = 0;
    history->size += 1;
    history->commands = realloc(history->commands, sizeof(char *) *
        (history->size + 1));
    history->commands[history->size] = NULL;
    history->commands[history->size - 1] = strdup(command);
    return history;
}

history_t *history_init(void)
{
    history_t *history = malloc(sizeof(history_t));
    char *filename = (getenv("HOME")) ?
        pstrmerge(getenv("HOME"), ".42sh_history") : ".42sh_history";
    FILE *file = fopen(filename, "r");
    char *line = NULL;
    history_t *tmp = NULL;
    size_t len = 0;
    size_t nread;

    history->commands = malloc(sizeof(char *));
    history->size = 0;
    history->pos = 0;
    history->commands[0] = NULL;
    if (!file)
        return history;
    while ((nread = getline(&line, &len, file)) != -1) {
        history_push(line, history);
    }
    history->pos = history->size;
    return history;
}