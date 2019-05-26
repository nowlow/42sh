/*
** EPITECH PROJECT, 2019
** prompt
** File description:
** termkey
*/

#ifndef TERMKEY_H_
#define TERMKEY_H_

typedef struct termios termios_t;

termios_t *get_termios(void);
int reset_term(termios_t *term);

#endif /* !TERMKEY_H_ */