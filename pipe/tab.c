/*
** EPITECH PROJECT, 2019
** corewar asm
** File description:
** tab
*/

#include <stdlib.h>
#include "pipe.h"

int len_list(clist_t *list)
{
    int i = 0;

    for (; list != NULL; i++)
        list = list->next;
    return (i);
}
