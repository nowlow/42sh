/*
** EPITECH PROJECT, 2019
** prompt
** File description:
** strings
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "prompt/entry_edit.h"
#include "prompt/prompt.h"

char *strespace(char *str, cpos_t *pos, char c, winsize_t *w)
{
    size_t str_size = strlen(str);
    char *tmp = strdup(str);

    if (str_size > 0)
        str = realloc(str, str_size + 2);
    else {
        str = malloc(2);
        str[0] = 0;
    }
    if (pos->string)
        str[pos->string - 1] = c;
    else
        str[0] = c;
    str[str_size + 1] = 0;
    for (int i = pos->string - 1; i < str_size; i++)
        str[i + 1] = tmp[i];
    free(tmp);
    pos->string += 1;
    pos->cursor += (pos->cursor <= w->ws_col - pos->prompt) ? 1 : 0;
    return str;
}

char *strdespace(char *str, cpos_t *pos, char key, winsize_t *w)
{
    size_t str_size = (str) ? strlen(str) : 0;
    int keys_tab[] = {127, 21, 11, 0};
    char *(*funcs[])(char *, size_t, cpos_t *) = {
        &delete_one, &delete_all, &delete_from_cursor_pos
    };

    for (int i = 0; keys_tab[i]; i++) {
        if (key == keys_tab[i]) {
            str = funcs[i](str, str_size, pos);
            return str;
        }
    }
    return str;
}

void strcrput(size_t size, char c)
{
    char str[size + 1];

    for (int i = 0; i < size; i++)
        str[i] = c;
    write(1, str, size);
}