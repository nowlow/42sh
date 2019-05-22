/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** expression
*/

#include <stdlib.h>

char *skip_to_next_expression(char *line)
{
    int i;

    for (i = 0; line[i] == ' ' || line[i] == '\t'; i++);
    return (&line[i]);
}

char *get_parenthesis_expression(char *line, char **new_line)
{
    int size = 1;
    char *result;

    for (int depth = 1; depth; size++) {
        if (!line[size])
            return NULL;
        if (line[size] == '(')
            depth++;
        if (line[size] == ')')
            depth--;
    }
    result = malloc(sizeof(char) * (size + 1));
    if (!result)
        return NULL;
    for (int i = 0; i < size; i++)
        result[i] = line[i];
    line[size] = 0;
    *new_line = &line[size];
    return result;
}

char *get_normal_expression(char *line, char **new_line)
{
    int size;
    char *result;

    for (size = 0; line[size] && line[size] != ' ' && line[size] != '\t';
        size++);
    result = malloc(sizeof(char) * (size + 1));
    if (!result)
        return NULL;
    for (int i = 0; i < size; i++)
        result[i] = line[i];
    line[size] = 0;
    *new_line = &line[size];
    return result;
}
