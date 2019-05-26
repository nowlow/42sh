/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** redirection
*/

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "utils.h"
#include "shell.h"
#include "exec/exec.h"

void init_redirection(s_element *node)
{
    int fd;
    int a;

    for (a = 0; node->data.command->redirections[a]; a++);
    fd = open(node->data.command->redirections[a - 1],
    O_WRONLY | O_TRUNC | O_CREAT, S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR);
    dup2(fd, 1);
}