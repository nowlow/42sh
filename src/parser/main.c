/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** main
*/

#include "parser/parser.h"

void disp_indent(int ind)
{
    for (int i = 0; i < ind; i++) {
        printf("\t");
    }
}

void disp(s_element *ele, int indent)
{
    if (!ele)
        return;
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
        printf("argc: %d\n", ele->data.command->argc);
        for (int i = 0; ele->data.command->argv[i]; i++) {
            disp_indent(indent);
            printf("%s\n", ele->data.command->argv[i]);
        }
    }
    disp_indent(indent);
    printf("end: %p\n", ele);
    disp_indent(indent);
    printf("---------------------\n");
}

int main(int argc, char **argv)
{
    char ouais[] = "(salut \"ok ; bonjour\" ; pwd) | cat | od";
    s_element *el;

    el = parse(ouais);
    disp(el, 0);
    return 0;
}