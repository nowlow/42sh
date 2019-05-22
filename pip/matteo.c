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
    char **arguments = my_str_to_word_array(epur_str(av[1]), (' '));

    return (exec_pipe(arguments, out));
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
    if (close(tube[TUBE_ECRITURE]) == -1) {
	perror("Pere : erreur lors de la fermeture du tube en ecriture ");
        return (84);
    }
    if (dup2(tube[TUBE_LECTURE], STDIN_FILENO) == -1) {
	perror("Pere : erreur lors de la duplication du descripteur ");
	return (84);
    }
    if (close(tube[TUBE_LECTURE]) == -1) {
	perror("Pere : erreur lors de la fermeture du tube en lecture ");
	return (84);
    }
    return (0);
}

static int mid_pipe(char **av, int out, int ac)
{
    char **arguments = my_str_to_word_array(epur_str(av[ac]), (' '));
    int tube[2];
    pid_t pid;

    if (error_gestion(tube, &pid) != 0)
        return (84);
    if (pid == 0) {
        if (close(tube[TUBE_LECTURE]) == -1) {
            perror("Fils : erreur lors de la fermeture du tube en lecture ");
            return (84);
    }
        close_pipe(av, tube[TUBE_ECRITURE]);
    }
    if (close_and_copy_pipe(tube) != 0)
        return (84);
    return (exec_pipe(arguments, out));
}

static int create_pipe(char **av, int ac)
{
    int tube[2];
    pid_t pid;
    char **arguments = my_str_to_word_array(epur_str(av[ac]), (' '));

    if (error_gestion(tube, &pid) != 0)
	return (84);
    if (pid == 0) {
        if (close(tube[TUBE_LECTURE]) == -1) {
            perror("Fils : erreur lors de la fermeture du tube en lecture ");
            return (84);
        }
        while (ac > 1) {
            ac--;
            mid_pipe(av, tube[TUBE_ECRITURE], ac);
        }
    }
    if (close_and_copy_pipe(tube) != 0)
	return (84);
    if (execve(arguments[0], arguments, NULL) == -1) {
        perror("Pere : erreur lors de l'execution de wc ");
    }
}

int main(int ac, char **av)
{
    int i = ac - 1;

    if (ac < 3)
        return (84);
    create_pipe(av, i);
    return (0);
}
