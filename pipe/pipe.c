/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** pipe
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include "pipe.h"

char **my_str_to_word_array(char const *str, char c);
char *epur_str(char *str);

static int exec_pipe(char **args, int out)
{
    if (dup2(out, STDOUT_FILENO) == -1) {
        perror("Fils : erreur lors de la duplication du descripteur ");
        return (84);
    }
    if (dup2(out, STDERR_FILENO) == -1) {
        perror("Fils : erreur lors de la duplication du descripteur ");
        return (84);
    }
    if (close(out) == -1) {
        perror("Fils : erreur lors de la fermeture du tube en lecture ");
        return (84);
    }
    if (execve(args[0], args, NULL) == -1)
        perror("Fils : erreur lors de l'execution de ls ");
    return (84);
}

static int close_pipe(char **av, int out)
{
    return (exec_pipe(av, out));
}

static int error_gestion(int *tube, pid_t *pid)
{
    if (pipe(tube) == -1) {
	perror("Pere : erreur lors de la creation du tube ");
        return (84);
    }
    if ((*pid = fork()) == -1) {
        perror("Pere : erreur lors de la creation du fils ");
        return (84);
    }
    return (0);
}

static int close_and_copy_pipe(int *tube)
{
    if (close(tube[TUBE_WRITE]) == -1) {
	perror("Pere : erreur lors de la fermeture du tube en ecriture ");
        return (84);
    }
    if (dup2(tube[TUBE_READ], STDIN_FILENO) == -1) {
	perror("Pere : erreur lors de la duplication du descripteur ");
	return (84);
    }
    if (close(tube[TUBE_READ]) == -1) {
	perror("Pere : erreur lors de la fermeture du tube en lecture ");
	return (84);
    }
    return (0);
}

static int mid_pipe(clist_t *list, int out)
{
    int tube[2];
    pid_t pid;

    if (error_gestion(tube, &pid) != 0)
        return (84);
    if (pid == 0) {
        if (close(tube[TUBE_READ]) == -1) {
            perror("Fils : erreur lors de la fermeture du tube en lecture ");
            return (84);
        }
        close_pipe(clist->command->argv, tube[TUBE_WRITE]);
    }
    if (close_and_copy_pipe(tube) != 0)
        return (84);
    return (exec_pipe(clist->command->argv, out));
}

int *create_pipe(clist_t *list)
{
    clist_t *head = list;
    int tube[2];
    pid_t pid;

    if (error_gestion(tube, &pid) != 0)
	return (84);
    if (pid == 0) {
        if (close(tube[TUBE_READ]) == -1) {
            perror("Fils : erreur lors de la fermeture du tube en lecture ");
            return (84);
        }
        do {
            head = head->next;
            mid_pipe(head, tube[TUBE_WRITE]);
        } while (head);
    }
    if (close_and_copy_pipe(tube) != 0)
	return (84);
    if (execve(list->command->argv[0], list->command->argv, NULL) == -1) {
        perror("Pere : erreur lors de l'execution de wc ");
    }
}
