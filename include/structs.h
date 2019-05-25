/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** structs
*/

#ifndef STRUCTS_H_
#define STRUCTS_H_

typedef struct shell shell_t;

struct shell {
    char *name;
    char *prompt;
    int will_exit;
};

#endif /* !STRUCTS_H_ */
