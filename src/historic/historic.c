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

void history_write(history_t *history)
{
    char *filename = (getenv("HOME")) ?
        pstrmerge(getenv("HOME"), ".42sh_history") : ".42sh_history";
    int fd = open(filename, O_CREAT | O_WRONLY, 0666);
    FILE *file = fopen(filename, "wr");
    history_t *head = history;

    if (file == NULL)
        return;
    while (head) {
        if (head->command[0])
            fprintf(file, "%s\n", head->command);
        head = head->next;
    }
    fclose(file);
}

char *load_up(history_t **list)
{
    history_t *tmp = *list;

    if (tmp->next) {
        *list = tmp->next;
        return tmp->next->command;
    }
    return tmp->command;
}

char *load_down(history_t **list)
{
    history_t *tmp = *list;

    if (tmp->prev) {
        *list = tmp->prev;
        return tmp->prev->command;
    }
    return tmp->command;
}

history_t *history_push(char *command, history_t *list)
{
    history_t *new = malloc(sizeof(history_t));

    new->command = command;
    new->next = list;
    return new;
}

history_t *history_init(void)
{
    history_t *history = NULL;
    char *filename = (getenv("HOME")) ?
        pstrmerge(getenv("HOME"), ".42sh_history") : ".42sh_history";
    int fd = open(filename, O_RDONLY);
    char *line = NULL;
    history_t *tmp = NULL;

    if (fd == -1)
        return NULL;
    while ((line = get_next_line(fd)) != NULL) {
        history = history_push(line, history);
        if (tmp)
            tmp->prev = history;
        tmp = history;
    }
    line = calloc(1, 1);
    history = history_push(line, history);
    history->prev = NULL;
    if (tmp)
        tmp->prev = history;
    return history;
}