/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** special_keys
*/

#include <stdlib.h>
#include "prompt/prompt.h"

char *delete_one(char *str, size_t size, cpos_t *pos)
{
    for (int i = pos->string - 2; str[i + 1]; i++)
        str[(i > 0) ? i : 0] = str[i + 1];
    if (size)
        str[size - 1] = 0;
    if (pos->string > 1) {
        pos->cursor -= (pos->cursor > 1) ? 1 : 0;
        pos->string -= 1;
    }
    return str;
}

char *delete_all(char *str, size_t size, cpos_t *pos)
{
    free(str);
    str = malloc(1);
    str[0] = 0;
    pos->cursor = 1;
    pos->string = 1;
    return str;
}

char *delete_from_cursor_pos(char *str, size_t size, cpos_t *pos)
{
    if (pos->string <= 1) {
        str = delete_all(str, size, pos);
        return str;
    }
    str[pos->string - 1] = 0;
    str = realloc(str, pos->string);
    return str;
}