/*
** EPITECH PROJECT, 2019
** epur_str
** File description:
** epur_str
*/

#include <stdlib.h>

static int my_strlen(char const *str)
{
    int var = 0;

    for (int x = 0 ; str[x] != '\0' ; x += 1)
        var += 1;
    return (var);
}

char *epur_str(char *str)
{
    char sp;
    char *epu = malloc(sizeof(char) * my_strlen(str));
    int count = 0;

    sp = -1;
    for (int i = 0 ; str[i] != 0 ; i += 1) {
        if (str[i] != ' ' && str[i] != '\t')
        {
            if (sp == 1)
                epu[count++] = ' ';
            sp = 0;
            epu[count++] = str[i];
        }
        else if (sp == 0)
            sp = 1;
    }
    return (epu);
}
