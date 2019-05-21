/*
** EPITECH PROJECT, 2019
** prompt
** File description:
** display
*/

#include "prompt/prompt.h"
#include <sys/ioctl.h>
#include <stddef.h>
#include "utils.h"
#include <stdio.h>

void clrscr(char key)
{
    char *str = (key == 12) ? "\e[1;1H\e[2J" : "\n";

    write(1, str, strlen(str));
}

void prompt_put_str(winsize_t *w, char *str, size_t prompt_size, cpos_t *pos)
{
    size_t strsize = (str) ? strlen(str) : 0;
    int size_out = strsize - (w->ws_col - prompt_size);

    if (strsize + prompt_size < w->ws_col) {
        write(1, str, strsize);
        return;
    }
    if (pos->cursor > 1) {
        write(1, &str[size_out], strsize - size_out);
    } else if (pos->cursor == 0 && pos->string != 0) {
        write(1, &str[size_out], w->ws_col);
    } else {
        write(1, str, w->ws_col - prompt_size);
    }
}

void update_prompt(char *str, char *prompt, cpos_t *pos, winsize_t *w)
{
    size_t size = (str) ? strlen(str) : 0;
    size_t correct_pos = pos->string;
    size_t ref = 0;

    if (size > w->ws_col) {
        size = w->ws_col;
        correct_pos = pos->cursor;
        ref = pos->prompt;
    }
    write(1, "\r", 1);
    strcrput(w->ws_col, ' ');
    write(1, "\r", 1);
    write(1, prompt, strlen(prompt));
    prompt_put_str(w, str, count_cols(prompt), pos);
    // if (size + count_cols(prompt) < w->ws_col)
    // printf("[%d]", size - ref - (correct_pos - 1));
    // fflush(stdout);
        strcrput((size - ref - (correct_pos - 1)), '\b');
    // else
    //     strcrput(w->ws_col - correct_pos, '\b');
}