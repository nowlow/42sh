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

typedef struct winsize winsize_t;
typedef struct termios termios_t;

#define IS_PRINTABLE(c) (c >= 32 && c <= 126 || c == 0 || c == '\t') ? 1 : 0

void clrscr(char key);
char *strespace(char *str, size_t str_size, size_t n, char c);
char *strdespace(char *str, size_t str_size, size_t n, char key);
void strcrput(size_t size, char c);
char get_key(void);
void handle_special_keys(char *str, char key, unsigned int *pos);
char *user_entry(void);
void update_prompt(char *str, char *prompt, int *pos);

#endif /* !PROMPT_H_ */