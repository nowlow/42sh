/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** merge
*/

#include <stdlib.h>
#include "utils.h"

char *strmerge(char *s1, char *s2)
{
    int size = my_strlen(s1) + my_strlen(s2);
    char *merged = malloc(sizeof(char) * (size + 1));

    for (int i = 0; s1[i]; i++)
        merged[i] = s1[i];
    for (int i = 0; s2[i]; i++)
        merged[i + my_strlen(s1)] = s2[i];
    merged[size] = 0;
    return merged;
}