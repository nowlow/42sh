/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** bad_function
*/

#include <stdlib.h>
#include <stdio.h>
#include "parser/parser.h"

s_element *parse_ok(char *line, char separator)
{
    char **parts = line_to_parts(line, separator);
    int n_part;

    for (n_part = 0; parts[n_part]; n_part++);
    if (n_part <= 1) {
        dprintf(2, "Invalid null command. %s\n", parts[0]);
        return NULL;
    }
    for (int i = 0; parts[i]; i++) {
        printf("%d: %s\n", i, parts[i]);
    }
    return parts_to_elem(parts);
}

int is_only_parenthesis(char *line)
{
    int i = 1;

    line = skip_to_next_expression(line);
    if (!(line[0] == '('))
        return 0;
    for (int depth = 1; depth > 0; i++) {
        if (!line[i])
            return 0;
        if (line[i] == '(')
            depth++;
        if (line[i] == ')')
            depth--;
    }
    line = skip_to_next_expression(&line[i]);
    return (!line[0]);
}