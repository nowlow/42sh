/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** main
*/

#include "shell_manager.h"
#include "shell.h"
#include "prompt/prompt.h"
#include "prompt/termkey.h"

int main(int argc, char **argv, char **env)
{
    termios_t *term;
    shell_t *shell;
    int ret;

    if (isatty(0))
        term = get_termios();
    if (argc != 1)
        return 84;
    shell = shell_init();
    ret = run_shell(shell);
    shell_destroy(shell);
    if (isatty(0))
        reset_term(term);
    return ret;
}