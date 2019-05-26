/*
** EPITECH PROJECT, 2019
** aliases
** File description:
** string
*/

#include <stddef.h>
#include <stdbool.h>

size_t size_to_next_break(char *line, char *cbreak)
{
    size_t pos = 0;

    for (; line[pos]; pos++)
        for (size_t i = 0; cbreak[i]; i++)
            if (line[pos] == cbreak[i])
                return pos;
    return pos;
}

size_t count_breaks(char *line, char *cbreak)
{
    size_t pos = 0;
    bool passed = false;

    for (; line[pos]; pos++) {
        for (size_t i = 0; cbreak[i]; i++) {
            passed = (line[pos] == cbreak[i]) ? true : passed;
        }
        if (!passed)
            return pos;
        passed = false;
    }
    return pos;
}