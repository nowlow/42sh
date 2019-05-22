/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** main
*/

#include "parser.h"

void disp_indent(int ind)
{
    for (int i = 0; i < ind; i++) {
        printf("\t");
    }
}

void disp(s_element *ele, int indent)
{
    disp_indent(indent);
    printf("ptr: %p\n", ele);
    disp_indent(indent);
    printf("type: %d\n", ele->type);
    if (ele->type == TYPE_OPERATOR) {
        disp_indent(indent);
        printf("ope_type: %d\n", ele->data.operator->operator_type);
        disp_indent(indent);
        printf("a:\n");
        disp(ele->data.operator->a, indent + 1);
        disp_indent(indent);
        printf("b:\n");
        disp(ele->data.operator->b, indent + 1);
    }
    else
    {
        disp_indent(indent);
        printf("expr: %s\n", ele->data.expression);
    }
    disp_indent(indent);
    printf("end: %p\n", ele);
    disp_indent(indent);
    printf("---------------------\n");
}

int main(int argc, char **argv)
{
    s_element *ele;
    for (int i = 1; i < argc; i++) {
        ele = parse(argv[i]);
        disp(ele, 0);
    }
    return 0;
}