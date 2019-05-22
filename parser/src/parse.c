/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** parse
*/

#include <stdlib.h>
#include <string.h>
#include "parser.h"
#include "tab.h"

void parse_command(s_element *ele, char *line)
{
    char **parts = parse_line(line);

    for (int i = 0; parts[i]; i++) {
        printf("%d: |%s|\n", i, parts[i]);
    }

    for (int i = 0; parts[i]; i++) {
        if (strcmp(parts[i], "<") == 0) {
            i++;
            if (!parts[i])
                return;
            add_to_tab(&ele->data.command->sources,
                &ele->data.command->n_sources, parts[i]);
            continue;
        }
        if (strcmp(parts[i], ">") == 0) {
            i++;
            if (!parts[i])
                return;
            add_to_tab(&ele->data.command->redirections,
                &ele->data.command->n_redir, parts[i]);
            continue;
        }
        add_to_tab(&ele->data.command->argv,
            &ele->data.command->argc, parts[i]);
    }
}

void get_argc(s_command *cmd)
{
    int argc;

    for (argc = 0; cmd->argv[argc]; argc++);
    cmd->argc = argc;
}

s_element *to_expression_elem(char *expression)
{
    s_element *ele = malloc(sizeof(s_element));

    if (!ele)
        return NULL;
    ele->type = TYPE_COMMAND;
    ele->data.command = malloc(sizeof(s_command));
    if (!ele->data.command)
        return NULL;
    ele->data.command->argc = 10;
    ele->data.command->argv = init_tab(&ele->data.command->argc);
    ele->data.command->n_redir = 10;
    ele->data.command->redirections = init_tab(&ele->data.command->n_redir);
    ele->data.command->n_sources = 10;
    ele->data.command->sources = init_tab(&ele->data.command->n_sources);
    parse_command(ele, expression);
    get_argc(ele->data.command);
    return ele;
}

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

s_element *parts_to_elem(char **parts)
{
    int n_part;

    for (n_part = 0; parts[n_part]; n_part++);
    if (n_part == 0)
        return NULL;
    if (n_part == 1)
        return parse(parts[0]);
    if (!(strcmp(parts[1], ";") ^ strcmp(parts[1], "|")) || n_part < 3)
        return NULL;
    return to_operator_elem(parts);
}

char get_separator(char *line)
{
    int depth = 0;

    for (int i = 0; line[i]; i++) {
        if (line[i] == '(')
            depth++;
        if (line[i] == ')')
            depth--;
        if (depth == 0 && line[i] == ';')
            return ';';
    }
    depth = 0;
    for (int i = 0; line[i]; i++) {
        if (line[i] == '(')
            depth++;
        if (line[i] == ')')
            depth--;
        if (depth == 0 && line[i] == '|')
            return '|';
    }
    return 0;
}

s_element *parse_ok(char *line, char separator)
{
    char **parts = line_to_parts(line, separator);

    return parts_to_elem(parts);
}

s_element *parse(char *line)
{
    int separator = get_separator(line);

    if (separator == 0)
        return to_expression_elem(line);
    else
        return parse_ok(line, separator);
}