/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** cd
*/

#include "my.h"

void segfault(int signum)
{
    if (signum == SIGINT) {
        my_putstr(CYAN);
        my_putchar('\n');
        my_putstr("$ ");
        my_putstr(WHITE);
    }
}

int check_line_env(t_shell *shell, char *str)
{
    int i = 0;

    for (; shell->env[i] != NULL; i++)
        if (my_strncmp(shell->env[i], str, my_strlen(str)) == 0)
            return (i);
    return (-1);
}

static int change_pwd(t_shell *shell)
{
    int i = check_line_env(shell, "PWD");
    char *pwd = malloc(sizeof(char) * (4096 + 1));

    if (i == -1) {
        shell->tab[1] = "PWD";
        my_setenv(shell);
        i = check_line_env(shell, "PWD");
    }
    if (getcwd(pwd, 4096) == NULL)
        return (84);
    shell->env[i] = my_strcat("PWD=", pwd);
    if (pwd)
        free(pwd);
    return (0);
}

static char *pwd(char *str)
{
    int i = 0;
    char *new_pwd = malloc(sizeof(char) * (my_strlen(str) + 1));

    if (!new_pwd)
        return (NULL);
    while (str[i] != '=' && str[i] != '\0')
        i++;
    if (str[i + 1] != '\0')
        i++;
    for (int j = 0; str[i] != '\0'; j++) {
        new_pwd[j] = str[i];
        i++;
    }
    return (new_pwd);
}

void cd(t_shell *shell)
{
    int i = check_line_env(shell, "OLDPWD");
    char *str;
    struct stat stats;

    if (shell->tab[1] == NULL) {
        str = pwd(shell->env[i]);
        chdir(str);
    } else if (shell->tab[1] != NULL && shell->tab[2] != NULL)
        my_putstr_error("cd: Too many arguments.\n");
    else {
        stat(shell->tab[1], &stats);
        if (!(S_ISDIR(stats.st_mode))) {
            my_putstr_error(shell->tab[1]);
            my_putstr_error(": Not a directory.\n");
        } else if (chdir(shell->tab[1]) == -1) {
            my_putstr_error(shell->tab[1]);
            my_putstr_error(": No such file or directory.\n");
        }
    }
    change_pwd(shell);
}
