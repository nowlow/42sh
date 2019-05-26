/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
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
#include "prompt/prompt.h"
#include "parser/parser.h"
#include "exec/exec.h"

char *get_currentwdir(void)
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
    if (getenv("HOME") &&
        strcmp(dir_name, getenv("HOME")) == 0)
        wd = strmerge(wd, "~");
    else
        wd = strmerge(wd, name);
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
    git = strmerge(git, content);
    git = strmerge(git, "\e[34m)\e[0m");
    free(tmp);
    return git;
}

char *get_prompt(char *prompt, int ret)
{
    char *pr;
    void *ptr;

    pr = get_currentwdir();
    ptr = pr;
    pr = strmerge(pr, get_git_branch());
    pr = strmerge(pr, (!ret) ? "\e[32m" : "\e[31m");
    pr = strmerge(pr, prompt);
    pr = strmerge(pr, "\e[0m");
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
    int ret = 0;
    s_element *tree;

    signal(SIGINT, signal_handle);
    while (shell->will_exit != 1 &&
        (entry = user_entry(get_prompt(PROMPT, ret), shell))) {
        if (entry[0] != '\0' && entry)
            ret = exec_line(entry, shell);
    }
    if (isatty(0))
        printf("exit\n");
    return (shell->will_exit == 1) ? ret : 0;
}