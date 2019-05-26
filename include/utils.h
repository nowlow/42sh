/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** utils
*/

#ifndef UTILS_H_
#define UTILS_H_

#include <unistd.h>

#define IS_NUM(c) (c >= '0' && c <= '9') ? 1 : 0
#define IS_SPACE(x) (x == ' ' || x == 0 || x == '\t') ? 1 : 0

/// returns char *'s length
size_t my_strlen(char const *str);

/// print char *'s content in standard output
void my_putstr(char const *str);

///  print char *'s content in error output
void my_puterr(char const *str);

char **replace_env_vars(char **tb);

/// concatenates 2 string in a third
char *strmerge(char *s1, char *s2);

char *pstrmerge(char *s1, char *s2);

/// returns a char **'s lenght
int double_array_len(char **var);

/// returns first number in a string
int my_getnbr(char *str);

/// Duplicate a string
char *my_strdup(char const *src);

/// Compare n chars of two strings
int my_strncmp(char const *s1, char const *s2, int n);

/// Compare two strings
int my_strcmp(char const *s1, char const *s2);

/// Count columns that take a string
size_t count_cols(char const *str);

size_t size_to_next_break(char *line, char *cbreak);

size_t count_breaks(char *line, char *cbreak);

#endif /* !UTILS_H_ */
