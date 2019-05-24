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
#include <sys/stat.h>
#include <fcntl.h>

char *epur_str(char *str);

char **my_str_to_word_array(char const *str, char c);

int main(int ac, char **av)
{
    pid_t pid;
    int file;
    char **args;

    if (av[3] != NULL)
        file = open(av[2], O_WRONLY | O_APPEND, S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR);
    else
        file = open(av[2], O_WRONLY | O_TRUNC | O_CREAT, S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR);
    dup2(file, 1);
    args = my_str_to_word_array(epur_str(av[1]), ' ');
    while (pid = fork())
        if (pid == -1)
            printf("WTF\n");
        else
            execve(args[0], args, NULL);
    close(file);
}