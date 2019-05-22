/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** my_strdup
*/

#include <stdlib.h>
#include "utils.h"

char *my_strdup(char const *src)
{
    int src_l = my_strlen(src);
    char *dest = malloc(sizeof(char) * (src_l + 1));

    if (!src) {
        free(dest);
        return NULL;
    }
    for (int i = 0; i < src_l; i++)
        dest[i] = src[i];
    dest[src_l] = 0;
    return dest;
}