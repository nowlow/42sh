/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** str_tab_resize
*/

#include <stdlib.h>

char **init_tab(int *tab_size)
{
    char **parts = malloc(sizeof(char*) * (*tab_size + 1));

    if (!parts)
        return NULL;
    for (int i = 0; i <= *tab_size; i++)
        parts[i] = NULL;
    return parts;
}

void tab_resize(char ***tab, int *tab_size, int new_size)
{
    char **new = init_tab(&new_size);

    if (!new)
        return;
    for (int i = 0; (*tab)[i] && i < new_size; i++) {
        new[i] = (*tab)[i];
    }
    free(*tab);
    *tab = new;
    *tab_size = new_size;
}

void add_to_tab(char ***tab, int *tab_size, char *line)
{
    int place;

    if (!(*tab))
        return;
    for (place = 0; (*tab)[place]; place++);
    if (place >= *tab_size) {
        tab_resize(tab, tab_size, (*tab_size) + 10);
    }
    if (!(*tab))
        return;
    (*tab)[place] = line;
}