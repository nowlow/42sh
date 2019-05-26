/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** line_to_parts
*/

#include <stdlib.h>
#include <string.h>
#include "parser/tab.h"

static void update_depth(char current_char, int *depth, int *in_marks)
{
    if (current_char == '(')
        depth++;
    if (current_char == ')')
        depth--;
    if (current_char == '"')
        *in_marks = !(*in_marks);
}

char *get_cmd(char *line, char **new_line, char separator)
{
    int size = 0;
    char *result;
    int in_marks = 0;

    for (int depth = 0; (depth != 0 || in_marks || line[size] != separator);
        size++) {
        if (!line[size]) {
            if (depth)
                return NULL;
            else
                break;
        }
        update_depth(line[size], &depth, &in_marks);
    }
    result = malloc(sizeof(char) * (size + 1));
    if (!result)
        return NULL;
    for (int i = 0; i < size; i++)
        result[i] = line[i];
    result[size] = 0;
    *new_line = &line[size];
    return result;
}

char *get_operator(char *line, char **new_line, char separator)
{
    int size = 0;
    char *result;
    int in_marks = 0;

    for (int depth = 0; line[size] == separator && !(size >= 2 &&
        separator == ';'); size++) {
        if (!line[size]) {
            if (depth)
                return NULL;
            else
                break;
        }
        update_depth(line[size], &depth, &in_marks);
    }
    result = malloc(sizeof(char) * (size + 1));
    if (!result)
        return NULL;
    for (int i = 0; i < size; i++)
        result[i] = line[i];
    result[size] = 0;
    *new_line = &line[size];
    return result;
}

char *get_expression(char *line, char **new_line, char separator)
{
    if (!line[0])
        return NULL;
    if (line[0] == separator) {
        return get_operator(line, new_line, separator);
    }
    else {
        return get_cmd(line, new_line, separator);
    }
    return NULL;
}

char **line_to_parts(char *line, char separator)
{
    int parts_size = 10;
    char **parts = init_tab(&parts_size);
    char *buf = NULL;

    if (!parts)
        return NULL;
    while (buf = get_expression(line, &line, separator)) {
        add_to_tab(&parts, &parts_size, buf);
    }
    return parts;
}