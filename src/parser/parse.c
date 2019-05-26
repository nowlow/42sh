/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** parse
*/

#include <stdlib.h>
#include <string.h>
#include "parser/parser.h"
#include "parser/tab.h"

int check_separator(char *line, char separator)
{
    int depth = 0;
    int in_marks = 0;

    for (int i = 0; line[i]; i++) {
        if (line[i] == '(')
            depth++;
        if (line[i] == ')')
            depth--;
        if (line[i] == '"')
            in_marks = !in_marks;
        if (depth == 0 && !in_marks && line[i] == separator)
            return 1;
    }
    return 0;
}

char get_separator(char *line)
{
    char *separator_list = "&;|";

    for (int i = 0; i < separator_list[i]; i++) {
        if (check_separator(line, separator_list[i]))
            return separator_list[i];
    }
    return 0;
}

s_element *parts_to_elem(char **parts)
{
    int n_part;

    for (n_part = 0; parts[n_part]; n_part++);
    if (n_part == 0)
        return NULL;
    if (n_part == 1) {
        return parse(parts[0]);
    }
    if (!(strcmp(parts[1], ";") ^ strcmp(parts[1], "|")) || n_part < 3)
        return NULL;
    return to_operator_elem(parts);
}

char *remove_parenthesis(char *line)
{
    int i;
    int depth = 1;

    for (i = 0; line[i] != '('; i++)
        if (!line[i])
            return NULL;
    line[i] = ' ';
    while (depth > 0) {
        if (!line[i])
            return NULL;
        if (line[i] == '(')
            depth++;
        if (line[i] == ')')
            depth--;
        i++;
    }
    line[i - 1] = ' ';
    return line;
}

s_element *parse(char *line)
{
    int separator;

    if (!line)
        return NULL;
    separator = get_separator(line);
    if (separator == 0) {
        if (is_only_parenthesis(line))
            return parse(remove_parenthesis(line));
        else
            return to_command_elem(line);
    }
    else
        return parse_ok(line, separator);
}