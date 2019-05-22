/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** cursor_pos_edit
*/

#include <string.h>
#include "prompt/prompt.h"

void left_arrow(char *str, cpos_t *pos, winsize_t *w)
{
    pos->cursor -= (pos->cursor > 1) ? 1 : 0;
    pos->string -= (pos->string - 1) ? 1 : 0;
}

void right_arrow(char *str, cpos_t *pos, winsize_t *w)
{
    pos->cursor += (pos->cursor < strlen(str) + 1 &&
        pos->cursor + 1 < w->ws_col - pos->prompt) ? 1 : 0;
    pos->string += (pos->string <= strlen(str)) ? 1 : 0;
}

void up_arrow(char *str, cpos_t *pos, winsize_t *w)
{
    return;
}

void down_arrow(char *str, cpos_t *pos, winsize_t *w)
{
    return;
}