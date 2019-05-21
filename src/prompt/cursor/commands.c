/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** commands
*/

#include <string.h>
#include "prompt/prompt.h"

void goto_start(char *str, cpos_t *pos, winsize_t *w)
{
    pos->cursor = 1;
    pos->string = 1;
}

void goto_end(char *str, cpos_t *pos, winsize_t *w)
{
    pos->string = strlen(str) + 1;
    pos->cursor = (pos->string < w->ws_col) ? pos->string : w->ws_col;
}