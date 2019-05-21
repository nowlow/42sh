/*
** EPITECH PROJECT, 2019
** prompt
** File description:
** key
*/

#include <string.h>
#include <unistd.h>
#include "prompt/keys.h"
#include "prompt/cursor.h"

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
        return (c[0] != '\t') ? c[0] : ' ';
    return find_key(c);
}

int key_cursor(char key)
{
    char keys_tab[] = {-1, -2, -3, -4, 1, 5, -5, -6, 0};

    for (int i = 0; keys_tab[i]; i++) {
        if (keys_tab[i] == key)
            return i + 1;
    }
    return 0;
}

void handle_special_keys(char *str, char key, cpos_t *pos, winsize_t *w)
{
    void (*funcs[])(char *, cpos_t *, winsize_t *) = {
        &up_arrow, &left_arrow, &down_arrow,
        &right_arrow, &goto_start, &goto_end,
        &goto_start, &goto_end
    };
    int got = key_cursor(key) - 1;

    if (got != -1)
        funcs[got](str, pos, w);
}