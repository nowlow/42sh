/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** count_cols
*/

#include <unistd.h>
#include <stdio.h>

size_t count_cols(char const *str)
{
    size_t tmp = 0;
    size_t final_size = 0;

    for (int size = 0; str && str[size]; size++, final_size++) {
        if (str[size] == '\e') {
            for (tmp = size; str[tmp] && str[tmp] != 'm'; tmp++);
            final_size -= (tmp - size);
        }
    }
    return final_size;
}