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

char *strespace(char *str, size_t str_size, size_t n, char c)
{
    char *tmp = strdup(str);

    if (str_size > 0)
        str = realloc(str, str_size + 2);
    else {
        str = malloc(2);
        str[0] = 0;
    }
    if (str_size)
        str[n - 1] = c;
    else
        str[0] = c;
    str[str_size + 1] = 0;
    for (int i = n - 1; i < str_size; i++)
        str[i + 1] = tmp[i];
    free(tmp);
    return str;
}

char *strdespace(char *str, size_t str_size, size_t n, char key)
{
    int keys_tab[] = {127, 21, 11, 0};
    char *(*funcs[])(char *, size_t, size_t) = {
        &delete_one, &delete_all, &delete_from_cursor_pos
    };

    for (int i = 0; keys_tab[i]; i++) {
        if (key == keys_tab[i]) {
            str = funcs[i](str, str_size, n);
            return str;
        }
    }
    return str;
}

void strcrput(size_t size, char c)
{
    char str[size];

    for (int i = 0; i < size; i++)
        str[i] = c;
    write(1, str, size);
}