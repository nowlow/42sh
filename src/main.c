/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** main
*/

#include "shell_manager.h"
#include "shell.h"

int main(int argc, char **argv, char **env)
{
    shell_t *shell;
    int ret;

    if (argc != 1)
        return 84;
    shell = shell_init("minishell", PROMPT, env);
    if (shell->env == NULL)
        shell->env = env_in_list(BASE_PATH, shell->env);
    ret = run_shell(shell);
    shell_destroy(shell);
    return ret;
}