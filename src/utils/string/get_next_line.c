/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** get_next_line
*/

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"
#include "utils.h"

char *my_reacat(int fd, char *buff)
{
    int i;
    int j;
    char *new;
    char *tmp = malloc(sizeof(char) * READ_SIZE + 1);
    size_t b_read = read(fd, tmp, READ_SIZE);

    if (b_read == 0)
        return NULL;
    tmp[b_read] = 0;
    new = malloc(my_strlen(buff) + my_strlen(tmp) + 1);
    for (i = 0; i < my_strlen(buff) + my_strlen(tmp) + 1; i += 1)
        new[i] = 0;
    for (i = 0; buff[i]; i += 1)
        new[i] = buff[i];
    for (j = 0; tmp[j]; j += 1)
        new[i + j] = tmp[j];
    new[i + j] = 0;
    free(tmp);
    return new;
}

char *get_line(char *str, int i)
{
    char *line = malloc(sizeof(char) * i + 1);

    for (int j = 0; j < i; j += 1)
        line[j] = str[j];
    line[i] = 0;
    free(str);
    return line;
}

char *get_next_line(int fd)
{
    char *buffer = malloc(sizeof(char) * (READ_SIZE + 1));
    int j = 0;

    buffer[0] = 0;
    while (buffer = my_reacat(fd, buffer))
        for (int i = 0; buffer[i]; i += 1)
            if (buffer[i] == '\n' || buffer[i] == 0)
                return get_line(buffer, i);
    return NULL;
}