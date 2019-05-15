/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** cursor
*/

#ifndef CURSOR_H_
#define CURSOR_H_

void down_arrow(char *str, unsigned int *pos);
void up_arrow(char *str, unsigned int *pos);
void right_arrow(char *str, unsigned int *pos);
void left_arrow(char *str, unsigned int *pos);
void goto_start(char *str, unsigned int *pos);
void goto_end(char *str, unsigned int *pos);

#endif /* !CURSOR_H_ */