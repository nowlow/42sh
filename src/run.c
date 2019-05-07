/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** run
*/

/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** run
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include "shell.h"
#include "get_next_line.h"

void print_prompt(char *prompt, env_t *env, int ret)
{
    char buffer[FILENAME_MAX];
    char *dir_name = getcwd(buffer, FILENAME_MAX);
    char *name;
    int last_slash = 0;

    env = (!env) ? build_env_list(__environ) : env;
    for (int i = 0; dir_name[i]; i ++)
        if (dir_name[i] == '/')
            last_slash = i;
    name = (last_slash != 0) ? &dir_name[last_slash + 1] : dir_name;
    my_putstr("\e[1m\e[36m");
    if (my_getenv("HOME", env) &&
        my_strcmp(dir_name, my_getenv("HOME", env)) == 0)
        my_putstr("~");
    else
        my_putstr(name);
    my_putstr((!ret) ? "\e[32m" : "\e[31m");
    my_putstr(prompt);
    my_putstr("\e[0m");
}

void signal_handle(int sig)
{
    (void) sig;
    if (isatty(0)) {
        write(1, "\b\b  \n", 5);
        print_prompt(PROMPT, NULL, 1);
    }
}

int run_shell(shell_t *shell)
{
    char *entry = NULL;
    cmd_t *cmd = NULL;
    cmd_t *tmp = NULL;
    int ret = 0;

    signal(SIGINT, signal_handle);
    do {
        if (entry)
            free(entry);
        if (isatty(0))
            print_prompt(shell->prompt, shell->env, ret);
        entry = get_next_line(0);
        if (entry != NULL && entry[0] != '\0') {
            cmd = my_array_to_cmd(entry);
            tmp = cmd;
            while (tmp) {
                shell->nb_pipes += (tmp->next_link == 1) ? 1 : 0;
                tmp = tmp->next;
            }
            ret = execmd(cmd, shell);
            cmd_destroy(cmd);
        }
    } while (shell->will_exit != 1 && entry);
    return (shell->will_exit == 1) ? ret : 0;
}