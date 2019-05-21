/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** cursor
*/

#ifndef CURSOR_H_
#define CURSOR_H_

#include "prompt.h"

void down_arrow(char *str, cpos_t *pos, winsize_t *w);
void up_arrow(char *str, cpos_t *pos, winsize_t *w);
void right_arrow(char *str, cpos_t *pos, winsize_t *w);
void left_arrow(char *str, cpos_t *pos, winsize_t *w);
void goto_start(char *str, cpos_t *pos, winsize_t *w);
void goto_end(char *str, cpos_t *pos, winsize_t *w);

#endif /* !CURSOR_H_ */