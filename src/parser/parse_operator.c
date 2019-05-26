/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** parse_operator
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "parser/parser.h"
#include "parser/tab.h"

operator_type_t get_operator_type(char *k)
{
    if (strcmp(k, "|") == 0)
        return TYPE_PIPE;
    if (strcmp(k, "||") == 0)
        return TYPE_OR;
    if (strcmp(k, "&&") == 0)
        return TYPE_SEPARATOR;
    for (int i = 0; k[i]; i++) {
        if (k[i] != ';')
            return TYPE_WRONG;
    }
    return TYPE_SEPARATOR;
}

s_element *to_operator_elem(char **parts, alias_t **aliases)
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
    ele->data.operator->operator_type = get_operator_type(parts[1]);
    if (ele->data.operator->operator_type == TYPE_WRONG)
        return NULL;
    ele->data.operator->a = parse(parts[0], aliases);
    ele->data.operator->b = parts_to_elem(&parts[2], aliases);
    if (!ele->data.operator->a | !ele->data.operator->b) {
        return NULL;
    }
    return ele;
}
