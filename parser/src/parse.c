/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** parse
*/

#include <stdlib.h>
#include <string.h>
#include "parser.h"

s_element *to_expression_elem(char *expression)
{
    s_element *ele = malloc(sizeof(s_element));

    if (!ele)
        return NULL;
    ele->type = TYPE_EXPRESSION;
    ele->data.expression = expression;
    return ele;
}

s_element *to_operator_elem(char **parts)
{
    s_element *ele = malloc(sizeof(s_element));

    if (!ele)
        return NULL;
    ele->type = TYPE_OPERATOR;
    ele->data.operator = malloc(sizeof(s_operator));
    if (!ele->data.operator) {
        free(ele);
        return NULL;
    }
    ele->data.operator->operator_type = TYPE_SEPARATOR;
    ele->data.operator->a = to_expression_elem(parts[0]);
    ele->data.operator->b = parts_to_elem(&parts[2]);
    return ele;
}

s_element *parts_to_elem(char **parts)
{
    int n_part;

    for (n_part = 0; parts[n_part]; n_part++);
    if (n_part == 0)
        return NULL;
    if (n_part == 1)
        return to_expression_elem(parts[0]);
    if (strcmp(parts[1], ";") || n_part < 3)
        return NULL;
    return to_operator_elem(parts);
}

s_element *parse(char *line)
{
    char **parts = line_to_parts(line);

    if (!parts)
        return NULL;
    return parts_to_elem(parts);
}