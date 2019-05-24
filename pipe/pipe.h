/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** pipe.h
*/

#ifndef PIPE_H_
#define PIPE_H_

#include "parser.h"

typedef struct clist {
    s_command *command;
    struct clist *next;
} clist_t;

typedef enum {
    TUBE_READ = 0,
    TUBE_WRITE = 1
}   e_tube;

#endif /* !PIPE_H_ */
