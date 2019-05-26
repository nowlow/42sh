/*
** EPITECH PROJECT, 2019
** prompt
** File description:
** prompt
*/

#include <string.h>
#include <stdlib.h>
#include "prompt/prompt.h"
#include "utils.h"
#include <stdbool.h>
#include "historic.h"
#include "shell.h"

char *refund_str(char *str, char key, cpos_t *pos, winsize_t *w)
{
    if (!key_cursor(key)) {
        if (IS_PRINTABLE(key)) {
            str = strespace(str, pos, key, w);
        } else if (pos->string > 0) {
            str = strdespace(str, pos, key, w);
        }
    } else
        str = handle_special_keys(str, key, pos, w);
    return str;
}

char *prompt(char *display)
{
    char *str = malloc(1);
    cpos_t pos = {0, 0, count_cols(display), history_init()};
    char key = 0;
    winsize_t w;

    str[0] = 0;
    do {
        ioctl(0, TIOCGWINSZ, &w);
        if (key == 4)
            return NULL;
        if (key != 12 && key != 3)
            str = refund_str(str, key, &pos, &w);
        else
            clrscr(key);
        update_prompt(str, display, &pos, &w);
    } while ((key = get_key()) != '\n');
    pos.historic = history_push(str, pos.historic);
    history_write(pos.historic);
    write(1, "\n", 1);
    return str;
}

char *user_entry(char *display, shell_t *shell)
{
    size_t nread = 0;
    char *command = NULL;
    size_t len = 0;

    if (isatty(0) && getenv("TERM")) {
        return prompt(display);
    }
    if (isatty(0))
        write(1, display, strlen(display));
    nread = getline(&command, &len, stdin);
    if (nread == -1)
        return NULL;
    if (command[strlen(command) - 1] == '\n')
        command[strlen(command) - 1] = 0;
    return command;
}