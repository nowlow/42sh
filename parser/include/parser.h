/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** parser
*/

#ifndef PARSER_H_
#define PARSER_H_

typedef struct s_command
{
    int argc;
    char **argv;
} s_command;

typedef enum operator_type
{
    TYPE_SEPARATOR,
    TYPE_PIPE
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

s_element *parse(char *line);

void *free_all(s_element *element);

char **line_to_parts(char *line);

s_element *parts_to_elem(char **parts);

char *get_expression(char *line, char **new_line);
char *skip_to_next_expression(char *line);

#endif /* !PARSER_H_ */
