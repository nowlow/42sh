/*
** EPITECH PROJECT, 2019
** prompt
** File description:
** prompt
*/

#include <string.h>
#include "prompt.h"

static char *refund_str(char *str, char key, unsigned int *pos)
{
    unsigned int cursor_pos = *pos;
    size_t size = strlen(str);

    if (key >= 0) {
        if (IS_PRINTABLE(key)) {
            str = strespace(str, size, cursor_pos, key);
            cursor_pos += 1;
        } else if (cursor_pos > 0) {
            str = strdespace(str, size, cursor_pos, key);
            cursor_pos -= (cursor_pos > 1 && key == 127) ? 1 : 0;
        }
    } else
        handle_special_keys(str, key, &cursor_pos);
    *pos = cursor_pos;
    return str;
}

char *prompt(char *display)
{
    char *str = malloc(1);
    unsigned int cursor_pos = 0;
    char key = 0;
    unsigned int max_size = 1;

    str[0] = 0;
    do {
        if (key == 4)
            return NULL;
        if (key != 12) {
            str = refund_str(str, key, &cursor_pos);
            max_size += (strlen(str) >= max_size) ? 1 : 0;
        } else
            clrscr();
        update_prompt(str, display, &cursor_pos, max_size);
    } while ((key = get_key()) != '\n');
    write(1, "\n", 1);
    return str;
}

char *user_entry(void)
{
    size_t nread = 0;
    char *command = NULL;
    size_t len = 0;

    if (isatty(0))
        return prompt("> ");
    nread = getline(&command, &len, stdin);
    if (nread == -1)
        return NULL;
    if (command[strlen(command) - 1] == '\n')
        command[strlen(command) - 1] = 0;
    return command;
}