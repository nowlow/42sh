/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** parser
*/

#ifndef PARSER_H_
#define PARSER_H_

#include "aliases.h"

typedef struct s_command
{
    int argc;
    char **argv;
    int n_redir;
    char **redirections;
    int n_sources;
    char **sources;
} s_command;

typedef enum operator_type
{
    TYPE_SEPARATOR,
    TYPE_PIPE,
    TYPE_OR,
    TYPE_WRONG
} operator_type_t;

typedef struct s_operator
{
    operator_type_t operator_type;
    struct s_element *a;
    struct s_element *b;
} s_operator;

typedef enum elem_type
{
    TYPE_OPERATOR,
    TYPE_COMMAND,
    TYPE_EXPRESSION,
} elem_type_t;

typedef struct s_element
{
    elem_type_t type;
    union {
        s_command *command;
        s_operator *operator;
        char *expression;
    } data;
} s_element;

s_element *parse(char *line, alias_t **aliases);

void *free_all(s_element *element);

char **line_to_parts(char *line, char separator);

s_element *parts_to_elem(char **parts, alias_t **aliases);

char *get_expression(char *line, char **new_line);
char *skip_to_next_expression(char *line);

char **parse_line(char *line);

s_element *parse_ok(char *line, char separator, alias_t **aliases);

int is_only_parenthesis(char *line);

s_element *to_operator_elem(char **parts, alias_t **alliases);

s_element *to_command_elem(char *expression, alias_t **aliases);

#endif /* !PARSER_H_ */
