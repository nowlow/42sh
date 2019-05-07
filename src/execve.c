/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** execve
*/

#include "my.h"

int execve_part_2(pid_t pid)
{
    int status;
    int error;

    pid = waitpid(pid, &status, 0);
    if (pid == -1)
        return (84);
    if (WIFSIGNALED(status)) {
        error = WTERMSIG(status);
        if (WCOREDUMP(status) && error == 11) {
            my_putstr_error("Segmentation fault (core dumped)\n");
            return (0);
        }else if (error == 11) {
            my_putstr_error("Segmentation fault\n");
            return (0);
        }
        if (error == 8)
            my_putstr_error("Floating exception (core dumped)\n");
    }
    return (0);
}

char *cut_env(char **envp, char *str)
{
    int j = -1;
    int i = 0;

    for (; envp[i] != NULL; i++)
        if (my_strncmp(envp[i], str, my_strlen(str)) == 0)
            j = i;
    if (j != -1)
        return (&(envp[j])[my_strlen(str) + 1]);
    else
        return (NULL);
}
