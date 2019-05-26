/*
** EPITECH PROJECT, 2019
** prompt
** File description:
** prompt
*/

#ifndef PROMPT_H_
#define PROMPT_H_

#include <term.h>
#include <sys/ioctl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "historic.h"
#include "structs.h"

typedef struct winsize winsize_t;
typedef struct termios termios_t;
typedef struct cpos cpos_t;

#define IS_PRINTABLE(c) (c >= 32 && c <= 126 || c == 0 || c == '\t') ? 1 : 0

#define IS_GETTABLE(c) (c != '\e') ? 1 : 0

struct cpos {
    unsigned int cursor;
    unsigned int string;
    size_t prompt;
    history_t *historic;
};

void clrscr(char key);
char *strespace(char *str, cpos_t *pos, char c, winsize_t *w);
char *strdespace(char *str, cpos_t *pos, char key, winsize_t *w);
void strcrput(int size, char c);
char get_key(void);
char *handle_special_keys(char *str, char key, cpos_t *pos, winsize_t *w);
char *user_entry(char *display, shell_t *shell);
void update_prompt(char *str, char *prompt, cpos_t *pos, winsize_t *w);
int key_cursor(char key);

#endif /* !PROMPT_H_ */