/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** special_keys
*/

#include <stdlib.h>

char *delete_one(char *str, size_t size, size_t cpos)
{
    for (int i = cpos - 2; str[i + 1]; i++)
        str[i] = str[i + 1];
    if (size)
        str[size - 1] = 0;
    return str;
}

char *delete_all(char *str, size_t size, size_t cpos)
{
    free(str);
    str = malloc(1);
    str[0] = 0;
    return str;
}

char *delete_from_cursor_pos(char *str, size_t size, size_t cpos)
{
    str[cpos - 1] = 0;
    str = realloc(str, cpos - 1);
    return str;
}