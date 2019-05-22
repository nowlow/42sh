/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** double_array
*/

int double_array_len(char **var)
{
    char **vari = var;

    for (; *vari; vari++);
    return vari - var;
}