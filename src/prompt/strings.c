/*
** EPITECH PROJECT, 2019
** prompt
** File description:
** strings
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>

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
    int minus = 2;

    if (key == 127) {
        for (int i = n - minus; str[i + 1]; i++)
            str[i] = str[i + 1];
        if (str_size)
            str[str_size - 1] = 0;
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