/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** parse_operator
*/

#include <stdlib.h>
#include <string.h>
#include "parser.h"
#include "tab.h"

operator_type_t get_operator_type(char *k)
{
    if (strcmp(k, ";") == 0)
        return TYPE_SEPARATOR;
    if (strcmp(k, "|") == 0)
        return TYPE_PIPE;
    return TYPE_SEPARATOR;
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
    ele->data.operator->operator_type = get_operator_type(parts[1]);
    ele->data.operator->a = parse(parts[0]);
    ele->data.operator->b = parts_to_elem(&parts[2]);
    return ele;
}
