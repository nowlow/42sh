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
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <unistd.h>
#include <signal.h>
#include "shell.h"
#include "get_next_line.h"
#include "prompt.h"

char *get_currentwdir(env_t *env)
{
    char *name;
    int last_slash = 0;
    char buffer[FILENAME_MAX];
    char *dir_name = getcwd(buffer, FILENAME_MAX);
    char *wd;

    for (int i = 0; dir_name[i]; i++)
        if (dir_name[i] == '/')
            last_slash = i;
    name = (last_slash != 0) ? &dir_name[last_slash + 1] : dir_name;
    wd = "\e[1m\e[36m";
    if (my_getenv("HOME", env) &&
        my_strcmp(dir_name, my_getenv("HOME", env)) == 0)
        wd = my_strmerge(wd, "~");
    else
        wd = my_strmerge(wd, name);
    return wd;
}

char *get_git_branch(void)
{
    int fd = open(".git/HEAD", O_RDONLY);
    char *git = " \e[34mgit:(\e[31m\e[1m";
    int last_slash = 0;
    char *content;
    void *tmp;

    if (fd == -1)
        return "";
    content = get_next_line(fd);
    tmp = (void *)content;
    for (int i = 0; content && content[i]; i++)
        if (content[i] == '/')
            last_slash = i + 1;
    content = (content) ? &content[last_slash] : NULL;
    if (!content || content[0] == 0)
        return "";
    git = my_strmerge(git, content);
    git = my_strmerge(git, "\e[34m)\e[0m");
    free(tmp);
    return git;
}

char *get_prompt(char *prompt, env_t *env, int ret)
{
    char *pr;
    void *ptr;

    env = (!env) ? build_env_list(__environ) : env;
    pr = get_currentwdir(env);
    ptr = pr;
    pr = my_strmerge(pr, get_git_branch());
    pr = my_strmerge(pr, (!ret) ? "\e[32m" : "\e[31m");
    pr = my_strmerge(pr, prompt);
    pr = my_strmerge(pr, "\e[0m");
    free(ptr);
    return pr;
}

void signal_handle(int sig)
{
    (int)sig;
}

int run_shell(shell_t *shell)
{
    char *entry = NULL;
    cmd_t *cmd = NULL;
    cmd_t *tmp = NULL;
    int ret = 0;

    signal(SIGINT, signal_handle);
    while (shell->will_exit != 1 &&
        (entry = user_entry(get_prompt(PROMPT, shell->env, ret)))) {
        if (entry[0] != '\0') {
            cmd = my_array_to_cmd(entry);
            tmp = cmd;
            while (tmp) {
                shell->nb_pipes += (tmp->next_link == 1) ? 1 : 0;
                tmp = tmp->next;
            }
            ret = execmd(cmd, shell);
            cmd_destroy(cmd);
        }
    }
    return (shell->will_exit == 1) ? ret : 0;
}