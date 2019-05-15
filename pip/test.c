/**
 * Ce programme illustre le fonctionnement de l'appel systeme dup2. Ici, un
 * tube est cree entre un fils et un pere. La sortie du tube est dupliquee
 * vers la sortie standard, puis la commande ls est executee. L'entree du
 * tube est dupliquee vers l'entree standard, puis la commande wc est executee.
 * Ce programme est equivalant a la commande : ls -l | wc -l
 * @author Cyril Rabat
 * @version 23/01/2014
 */
#include <stdlib.h>    /* Pour exit, EXIT_SUCCESS, EXIT_FAILURE */
#include <stdio.h>     /* Pour printf, perror */
#include <unistd.h>    /* Pour fork, pipe, dup2, execve */
#include <sys/wait.h>  /* Pour waitpid */
#include <sys/types.h> /* Pour pid_t */

char **my_str_to_word_array(char const *str, char c);

char *epur_str(char *str);

#define TUBE_LECTURE  0
#define TUBE_ECRITURE 1

void fils(char **argv, int out) {
    char **arguments = my_str_to_word_array(epur_str(argv[1]), (' '));

    /* Ecrasement des descripteurs des sorties (STDOUT et STDERR) */
    if(dup2(out, STDOUT_FILENO) == -1) {
        perror("Fils : erreur lors de la duplication du descripteur ");
        exit(EXIT_FAILURE);
    }
    if(dup2(out, STDERR_FILENO) == -1) {
        perror("Fils : erreur lors de la duplication du descripteur ");
        exit(EXIT_FAILURE);
    }

    /* Fermeture du tube en ecriture */
    if(close(out) == -1) {
        perror("Fils : erreur lors de la fermeture du tube en lecture ");
        exit(EXIT_FAILURE);
    }

    /* Execution de ls */
    if(execve(arguments[0], arguments, NULL) == -1) {
        perror("Fils : erreur lors de l'execution de ls ");
    }
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[])
{
    int tube[2];
    pid_t pid;
    char **arguments = my_str_to_word_array(epur_str(argv[2]), (' '));

    /* Creation du tube */
    if(pipe(tube) == -1) {
        perror("Pere : erreur lors de la creation du tube ");
        exit(EXIT_FAILURE);
    }

    /* Creation du fils */
    if((pid = fork()) == -1) {
        perror("Pere : erreur lors de la creation du fils ");
        exit(EXIT_FAILURE);
    }
    if(pid == 0) {
        /* Fermeture du tube en lecture */
        if(close(tube[TUBE_LECTURE]) == -1) {
            perror("Fils : erreur lors de la fermeture du tube en lecture ");
            exit(EXIT_FAILURE);
        }
        fils(argv, tube[TUBE_ECRITURE]);
    }

    /* Fermeture du tube en ecriture */
    if(close(tube[TUBE_ECRITURE]) == -1) {
        perror("Pere : erreur lors de la fermeture du tube en ecriture ");
        exit(EXIT_FAILURE);
    }

    /* Ecrasement du descripteur d'entree standard (STDIN) */
    if(dup2(tube[TUBE_LECTURE], STDIN_FILENO) == -1) {
        perror("Pere : erreur lors de la duplication du descripteur ");
        exit(EXIT_FAILURE);
    }

    /* Fermeture du tube en lecture */
    if(close(tube[TUBE_LECTURE]) == -1) {
        perror("Pere : erreur lors de la fermeture du tube en lecture ");
        exit(EXIT_FAILURE);
    }

    /* Execution de ls */
    if(execve(arguments[0], arguments, NULL) == -1) {
        perror("Pere : erreur lors de l'execution de wc ");
    }

    return EXIT_FAILURE;
}
