/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** commands
*/

#include <string.h>

void goto_start(char *str, unsigned int *pos)
{
    unsigned int cursor_pos = *pos;

    cursor_pos = 1;
    *pos = cursor_pos;
}

void goto_end(char *str, unsigned int *pos)
{
    unsigned int cursor_pos = *pos;

    cursor_pos = strlen(str) + 1;
    *pos = cursor_pos;
}