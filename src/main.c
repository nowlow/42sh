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
    shell_t *shell;
    int ret;

    if (argc != 1)
        return 84;
    shell = shell_init();
    ret = run_shell(shell);
    if (isatty(0))
        shell->term = get_termios();
    shell_destroy(shell);
    if (isatty(0))
        reset_term(shell->term);
    return ret;
}