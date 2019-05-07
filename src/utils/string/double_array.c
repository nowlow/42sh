/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** double_array
*/

int double_array_len(char **var)
{
    char **vari = var;

    for (; *vari; vari++);
    return vari - var;
}