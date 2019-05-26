/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** error
*/

#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include "shell.h"

int child_perror(int child)
{
    int plus = 0;

    if (WTERMSIG(child) == SIGABRT)
        my_puterr("Abort");
    else if (WTERMSIG(child) == SIGFPE)
        my_puterr("Floating point exeption");
    if (WTERMSIG(child) == SIGSEGV)
        my_puterr("Segmentation fault");
    else if (WTERMSIG(child) == SIGBUS)
        my_puterr("Bus error");
    plus = WTERMSIG(child);
    if (WCOREDUMP(child))
        my_puterr(" (core dumped)");
    my_puterr("\n");
    return plus;
}

int child_error_handle(int child, shell_t *shell)
{
    int sig = WIFSIGNALED(child);
    int plus = 0;

    if (sig) {
        plus = child_perror(child);
        return 128 + plus;
    } else if (WIFEXITED(child))
        return WEXITSTATUS(child);
    return child;
}