/*
** EPITECH PROJECT, 2019
** parser
** File description:
** get_delim
*/

#include "parser/parser.h"

int get_op(char *line)
{
    for (int a = 0; line && line[a]; a++){
        if (line[a] == '|')
            return (TYPE_PIPE);
        if (line[a] == ';')
            return (TYPE_SEPARATOR);
    }
    return (-1);
}