/*
** EPITECH PROJECT, 2019
** prompt
** File description:
** key
*/

#include <string.h>
#include <unistd.h>
#include "keys.h"

static int key_match(char const k1[4], char const k2[4])
{
    for (int i = 0; i < 4; i++) {
        if (k1[i] != k2[i])
            return 0;
    }
    return 1;
}

static char find_key(char c[4])
{
    for (int i = 0; special_keys_code[i][0]; i++) {
        if (key_match(c, special_keys_code[i]))
            return (i + 1) * -1;
    }
    return '^';
}

char get_key(void)
{
    char c[4] = {0, 0, 0};

    read(0, &c, 3);
    if (c[1] == 0)
        return c[0];
    return find_key(c);
}

void handle_special_keys(char *str, char key, unsigned int *pos)
{
    int cursor_pos = *pos;

    switch (key) {
    case LEFT_ARROW:
        cursor_pos -= (cursor_pos > 1) ? 1 : 0;
        break;
    case RIGHT_ARROW:
        cursor_pos += (cursor_pos < strlen(str) + 1) ? 1 : 0;
        break;
    default:
        break;
    }
    *pos = cursor_pos;
}