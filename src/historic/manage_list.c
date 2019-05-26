/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** manage_list.c
*/

#include "historic.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include "utils.h"

// history_t *create_list(void)
// {
//     int count = 1;
//     history_t *list = malloc(sizeof(history_t));
//     history_t *head = list;

//     list->number = 0;
//     list->command = calloc(1, 1);
//     list->empty = true;
//     list->previous = NULL;
//     list->next = malloc(sizeof(history_t));
//     list->next->head = list;
//     list = list->next;
//     while (count != 100) {
//         list->number = count;
//         list->command = NULL;
//         list->empty = true;
//         list->next = malloc(sizeof(history_t));
//         list->next->previous = list;
//         list->next->head = list->head;
//         list = list->next;
//         count += 1;
//     }
//     list = head;
//     list->head = head;
//     return (list);
// }

// history_t *manage_linked_list(history_t *list)
// {
//     list = list->head;
//     while (list->number != 99) {
//         list->empty = true;
//         list = list->next;
//     }
//     return (list);
// }

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