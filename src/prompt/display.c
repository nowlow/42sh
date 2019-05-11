/*
** EPITECH PROJECT, 2019
** prompt
** File description:
** display
*/

#include "prompt.h"
#include <sys/ioctl.h>
#include <stddef.h>

void clrscr(void)
{
    char *str = "\e[1;1H\e[2J";

    write(1, str, strlen(str));
}

void put_long_str(winsize_t *w, char *str, size_t prompt_size, int *pos)
{
    int size_out = strlen(str) - (w->ws_col - prompt_size - 4);
    int c_pos = *pos;

    if (c_pos > size_out) {
        write(1, "...", 3);
        write(1, &str[size_out], strlen(str) - size_out);
    } else if (strlen(&str[size_out]) > w->ws_col - 8) {
        write(1, "...", 3);
        write(1, &str[size_out], w->ws_col - 8);
        write(1, "...", 3);
    } else {
        write(1, str, w->ws_col - 4);
        write(1, "...", 3);
    }
    *pos = c_pos;
}

void update_prompt(char *str, char *prompt, int *pos, int max_size)
{
    winsize_t w;

    ioctl(0, TIOCGWINSZ, &w);
    write(1, "\r", 1);
    strcrput(w.ws_col, ' ');
    write(1, "\r", 1);
    write(1, prompt, strlen(prompt));
    if (strlen(str) + strlen(prompt) > w.ws_col - 4) {
        put_long_str(&w, str, strlen(prompt), pos);
    } else
        write(1, str, strlen(str));
    for (int i = 0; i < strlen(str) - (*pos - 1) && i < strlen(str); i++)
        write(1, "\b", 1);
}