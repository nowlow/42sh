/*
** EPITECH PROJECT, 2019
** parser
** File description:
** command_parser
*/

#include "parser/tab.h"
#include "parser/parser.h"
#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

static int get_size_with(char *line)
{
    int size;

    for (size = 0; line[size] && (line[size] == '<' || line[size] == '>') &&
        line[size] != ' ' && line[size] != '\t'; size++);
    return (size);
}

static int get_size(char *line)
{
    int size;

    for (size = 0; line[size] && line[size] != '<' && line[size] != '>' &&
        line[size] != ' ' && line[size] != '\t'; size++);
    return (size);
}

static char *parse_command(char *line, char **new_line)
{
    int size = 1;
    char *result;

    if (line[0] == '>' || line[0] == '<')
        size = get_size_with(line);
    else
        size = get_size(line);
    result = malloc(sizeof(char) * (size + 1));
    if (!result)
        return NULL;
    for (int i = 0; i < size; i++)
        result[i] = line[i];
    result[size] = 0;
    *new_line = &line[size];
    return result;
}

char **parse_line(char *line)
{
    int tab_size = 1;
    char **args = init_tab(&tab_size);

    for (int arg = 0; line[0]; arg++)
        add_to_tab(&args, &tab_size,
        parse_command(skip_to_next_expression(line), &line));
    return (args);
}