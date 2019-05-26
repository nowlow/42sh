/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** parse_command
*/

#include <stdlib.h>
#include <string.h>
#include "parser/parser.h"
#include "parser/tab.h"

int k(s_element *ele, char **parts, int i)
{
    if (strcmp(parts[i], "<") == 0) {
        i++;
        if (!parts[i])
            return 0;
        add_to_tab(&ele->data.command->sources,
            &ele->data.command->n_sources, parts[i]);
        return 1;
    }
    if (strcmp(parts[i], ">") == 0) {
        i++;
        if (!parts[i])
            return 0;
        add_to_tab(&ele->data.command->redirections,
            &ele->data.command->n_redir, parts[i]);
        return 1;
    }
    add_to_tab(&ele->data.command->argv,
        &ele->data.command->argc, parts[i]);
}

void parse_command(s_element *ele, char *line)
{
    char **parts = parse_line(line);

    for (int i = 0; parts[i]; i++) {
        if (!k(ele, parts, i))
            break;
    }
}

void get_argc(s_command *cmd)
{
    int argc;

    for (argc = 0; cmd->argv[argc]; argc++);
    cmd->argc = argc;
}

s_element *to_command_elem(char *expression, alias_t **aliases)
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
    expression = alias_handle(expression, aliases);
    parse_command(ele, expression);
    get_argc(ele->data.command);
    return ele;
}