/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** cursor_pos_edit
*/

#include <string.h>

void left_arrow(char *str, unsigned int *pos)
{
    unsigned int cursor_pos = *pos;

    cursor_pos -= (cursor_pos > 1) ? 1 : 0;
    *pos = cursor_pos;
}

void right_arrow(char *str, unsigned int *pos)
{
    unsigned int cursor_pos = *pos;

    cursor_pos += (cursor_pos < strlen(str) + 1) ? 1 : 0;
    *pos = cursor_pos;
}

void up_arrow(char *str, unsigned int *pos)
{
    unsigned int cursor_pos = *pos;

    *pos = cursor_pos;
}

void down_arrow(char *str, unsigned int *pos)
{
    unsigned int cursor_pos = *pos;

    *pos = cursor_pos;
}