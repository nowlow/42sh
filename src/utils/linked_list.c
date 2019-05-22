/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** linked_list
*/

#include <stdio.h>
#include "shell.h"

static cmd_t *get_last(cmd_t *list)
{
    cmd_t *tmp = list;

    while (tmp->next)
        tmp = tmp->next;
    return tmp;
}

static cmd_t *get_penultimate(cmd_t *list)
{
    cmd_t *tmp = list;

    while (tmp->next->next)
        tmp = tmp->next;
    return tmp;
}

cmd_t *reverse_cmd_list(cmd_t *list)
{
    cmd_t *first = list;
    cmd_t *b_last = get_last(list);
    cmd_t *last = NULL;
    cmd_t *penultimate = NULL;

    while (get_last(b_last) != first) {
        last = get_last(list);
        penultimate = get_penultimate(list);
        last->next = penultimate;
        penultimate->next = NULL;
    }
    list = b_last;
    return list;
}