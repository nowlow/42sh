/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** get_pipes
*/

#include "parser.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct clist {
    s_command *command;
    struct clist *next;
} clist_t;

clist_t *push(s_command *command, clist_t *list)
{
    clist_t *new = malloc(sizeof(clist_t));

    new->command = command;
    new->next = list;
    return new;
}

clist_t *get_pipes(s_element *tree, clist_t *list)
{
    s_element *head = tree;
    int count = 0;

    while (head->type == TYPE_SEPARATOR &&
        head->data.operator->a->type == TYPE_SEPARATOR) {
        head = head->data.operator->a;
    }
    if (head->data.operator->operator_type == TYPE_PIPE) {
        while (head->type == TYPE_SEPARATOR &&
            head->data.operator->operator_type == TYPE_PIPE) {
            if (head->data.operator->a->type == TYPE_OPERATOR)
                list = get_pipes(head->data.operator->a, list);
            if (head->data.operator->a->type != TYPE_OPERATOR)
                list = push(head->data.operator->a->data.command, list);
            if (head->data.operator->b->type != TYPE_OPERATOR)
                list = push(head->data.operator->b->data.command, list);
            head = head->data.operator->b;
        }
    }
    return list;
}