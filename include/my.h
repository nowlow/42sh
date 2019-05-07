/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** my.h
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <fcntl.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define CYAN "\033[1;34m"
#define PURPLE "\033[0;35m"
#define WHITE "\033[0m"

typedef struct s_shell
{
    char **tab;
    char **env;
    char *user;
    char *pwd;
    char *os;
}   t_shell;

void cd(t_shell *shell);
void my_exit(t_shell *shell);
void segfault(int);
void monitoring(t_shell *shell);
void my_env(t_shell *shell);
void my_setenv(t_shell *shell);
void my_unsetenv(t_shell *shell);
void my_putchar(char c);
void my_puterror(char c);
int check_line_env(t_shell *shell, char *str);
int execve_part_2(pid_t pid);
int my_putstr(char *str);
int my_putstr_error(char *str);
int len_env(char **envp);
int my_strlen(char const *str);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
int check_if_int_in_str(char const *str);
char *my_strdup(char const *src);
char *my_strcat(char const *dest, char const *src);
char *cut_env(char **envp, char *str);
char **my_str_to_word_array(char const *str);
char **parsing_env(char const *str);
char **copy_env(char **envp);
