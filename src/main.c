/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** main
*/

#include "my.h"

static int check_command(t_shell *shell)
{
    char *cmd[5] = {"exit", "cd", "setenv", "unsetenv", "env"};
    void (*tab[5])(t_shell *shell) = {my_exit, cd, my_setenv,
                                        my_unsetenv, my_env};

    for (int i = 0; i != 5; i++)
        if (my_strcmp(shell->tab[0], cmd[i]) == 0) {
            tab[i](shell);
            return (0);
        }
    return (1);
}

static char *command(char **path, char **tab)
{
    for (int i = 0; path[i] != NULL; i++)
        if (access(my_strcat(my_strcat(path[i], "/"), tab[0]), F_OK) == 0)
            return (my_strcat(my_strcat(path[i], "/"), tab[0]));
    if (access(tab[0], F_OK) == 0)
        return (tab[0]);
    my_putstr_error(tab[0]);
    my_putstr_error(": Command not found.\n");
    return (NULL);
}

static int my_command(t_shell *shell)
{
    char *test;
    pid_t pid;
    char **path;

    if (check_command(shell) == 1) {
        test = cut_env(shell->env, "PATH");
        path = parsing_env(test);
        if ((test = command(path, shell->tab)) == NULL)
            return (84);
        pid = fork();
        if (pid == -1)
            return (84);
        if (pid == 0) {
            execve(test, shell->tab, shell->env);
        } else
            execve_part_2(pid);
    }
    return (0);
}

int main(int ac, char **av, char **envp)
{
    t_shell shell;
    char *str;
    size_t len = 0;
    ssize_t check;

    shell.env = copy_env(envp);
    if (ac != 1)
        return (84);
    while (1) {
        if (isatty(0))
            monitoring(&shell);
        signal(SIGINT, segfault);
        if ((check = getline(&str, &len, stdin)) == -1)
            return (0);
        shell.tab = my_str_to_word_array(str);
        if (str[0] != '\0')
            my_command(&shell);
    }
    return (0);
}
