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

#define TUBE_LECTURE  0
#define TUBE_ECRITURE 1

char **my_str_to_word_array(char const *str, char c);
char *epur_str(char *str);
int mid_pipe(char **av, int out);

int close_pipe(char **av, int out)
{
    char **arguments = my_str_to_word_array(epur_str(av[1]), (' '));

    if(dup2(out, STDOUT_FILENO) == -1) {
        perror("Fils : erreur lors de la duplication du descripteur ");
        return (84);
    }
    if(dup2(out, STDERR_FILENO) == -1) {
        perror("Fils : erreur lors de la duplication du descripteur ");
        return (84);
    }
    if(close(out) == -1) {
        perror("Fils : erreur lors de la fermeture du tube en lecture ");
        return (84);
    }
    if(execve(arguments[0], arguments, NULL) == -1)
        perror("Fils : erreur lors de l'execution de ls ");
    return (84);
}

int mid_pipe(char **av, int out)
{
    char **arguments = my_str_to_word_array(epur_str(av[2]), (' '));
    int tube[2];
    pid_t pid;

    if(pipe(tube) == -1) {
        perror("Pere : erreur lors de la creation du tube ");
        return (84);
    }
    if((pid = fork()) == -1) {
        perror("Pere : erreur lors de la creation du fils ");
        return (84);
    }
    if(pid == 0) {
        if(close(tube[TUBE_LECTURE]) == -1) {
            perror("Fils : erreur lors de la fermeture du tube en lecture ");
            return (84);
	}
        close_pipe(av, tube[TUBE_ECRITURE]);
    }
    if(close(tube[TUBE_ECRITURE]) == -1) {
	perror("Pere : erreur lors de la fermeture du tube en ecriture ");
	exit(EXIT_FAILURE);
    }
    if(dup2(tube[TUBE_LECTURE], STDIN_FILENO) == -1) {
	perror("Pere : erreur lors de la duplication du descripteur ");
	exit(EXIT_FAILURE);
    }
    if(close(tube[TUBE_LECTURE]) == -1) {
	perror("Pere : erreur lors de la fermeture du tube en lecture ");
	exit(EXIT_FAILURE);
    }
//    if(execve(arguments[0], arguments, NULL) == -1) {
//	perror("Pere : erreur lors de l'execution de wc ");
//    }
    if(dup2(out, STDOUT_FILENO) == -1) {
        perror("Fils : erreur lors de la duplication du descripteur ");
        return (84);
    }
    if(dup2(out, STDERR_FILENO) == -1) {
        perror("Fils : erreur lors de la duplication du descripteur ");
        return (84);
    }
    if(close(out) == -1) {
        perror("Fils : erreur lors de la fermeture du tube en lecture ");
        return (84);
    }
    if(execve(arguments[0], arguments, NULL) == -1)
        perror("Fils : erreur lors de l'execution de ls ");
    return (84);
}

int create_pipe(char **av)
{
    int tube[2];
    pid_t pid;
    char **arguments = my_str_to_word_array(epur_str(av[3]), (' '));

    if(pipe(tube) == -1) {
	perror("Pere : erreur lors de la creation du tube ");
        return (84);
    }
    if((pid = fork()) == -1) {
        perror("Pere : erreur lors de la creation du fils ");
	return (84);
    }
    if(pid == 0) {
        if(close(tube[TUBE_LECTURE]) == -1) {
            perror("Fils : erreur lors de la fermeture du tube en lecture ");
            return (84);
        }
        mid_pipe(av, tube[TUBE_ECRITURE]);
    }
    if(close(tube[TUBE_ECRITURE]) == -1) {
	perror("Pere : erreur lors de la fermeture du tube en ecriture ");
        exit(EXIT_FAILURE);
    }
    if(dup2(tube[TUBE_LECTURE], STDIN_FILENO) == -1) {
	perror("Pere : erreur lors de la duplication du descripteur ");
        exit(EXIT_FAILURE);
    }
    if(close(tube[TUBE_LECTURE]) == -1) {
        perror("Pere : erreur lors de la fermeture du tube en lecture ");
	exit(EXIT_FAILURE);
    }
    if(execve(arguments[0], arguments, NULL) == -1) {
        perror("Pere : erreur lors de l'execution de wc ");
    }
}

int main(int ac, char **av)
{
    if (ac != 4)
        return (84);
    create_pipe(av);
    return (0);
}
