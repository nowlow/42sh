/*
** EPITECH PROJECT, 2018
** pushwap
** File description:
** put number in order
*/

#ifndef my_lib_
#define my_lib_
#define SUCESS 0
#define ERROR 84
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

// typedef struct history_s {
//     struct history_s *next;
//     bool empty;
//     char *command;
//     int number;
//     struct history_s *previous;
//     struct history_s *head;
// } history_t;

typedef struct history history_t;

struct history {
    int pos;
    int size;
    char **commands;
};

//additionnal_function.c
char *my_strcat(char *, char *);
//additionnal_function.c

//get_next_line.c
char *get_next_line(int);
//get_next_line.c

//print_error.c
void my_putstr_error(char *);
//print_error.c

//manage_list.c
history_t *create_list(void);
history_t *manage_linked_list(history_t *);
//manage_list.c

//my_strtoa.c
char **my_strtoa(char *);
//my_strtoa.c

// history_t *print_historic(history_t *list, int nbr);

// history_t *add_to_historic(char *command, history_t *list);

// char *open_the_file(char const *filepath);

history_t *history_init(void);
history_t *history_push(char *command, history_t *list);
char *load_down(history_t *list);
char *load_up(history_t *list);
void history_write(history_t *history);


#endif

