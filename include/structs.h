/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** structs
*/

#ifndef STRUCTS_H_
#define STRUCTS_H_

typedef struct cmd cmd_t;
typedef struct env env_t;
typedef struct shell shell_t;

struct cmd {
    int argc;
    char **argv;
    int next_link;
    int prev_link;
    cmd_t *next;
    int pipe[2];
    pid_t parent;
};

struct env {
    char *content;
    struct env *next;
};

struct shell {
    char *name;
    char *prompt;
    env_t *env;
    int will_exit;
    int nb_pipes;
};

#endif /* !STRUCTS_H_ */
