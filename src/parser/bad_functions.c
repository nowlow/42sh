/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** bad_function
*/

#include "parser/parser.h"

s_element *parse_ok(char *line, char separator)
{
    char **parts = line_to_parts(line, separator);

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