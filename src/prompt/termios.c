/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** keyboard
*/

#include <termios.h>
#include <string.h>
#include <term.h>
#include <ncurses.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "prompt.h"

termios_t *get_termios(void)
{
    termios_t *term = malloc(sizeof(termios_t));
    termios_t *base_term = malloc(sizeof(termios_t));
    char *term_env = getenv("TERM");

    if (!term_env || strlen(term_env) == 0)
        return NULL;
    tcgetattr(0, base_term);
    memcpy(term, base_term, sizeof(termios_t));
    tgetent(NULL, term_env);
    term->c_lflag &= ~(ICANON);
    term->c_lflag &= ~(ECHO);
    term->c_cc[VMIN] = 1;
    term->c_cc[VTIME] = 0;
    if (tcsetattr(0, TCSADRAIN, term) == -1)
        return NULL;
    free(term);
    return base_term;
}

int reset_term(termios_t *term)
{
    if (tcsetattr(0, TCSANOW, term) == -1)
        return -1;
    free(term);
    return 0;
}