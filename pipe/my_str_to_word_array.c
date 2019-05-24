/*
** EPITECH PROJECT, 2018
** my_str_to_word_array
** File description:
** task04
*/
#include <unistd.h>
#include <stdlib.h>

int my_putstr(char const *str);

int my_str_isalpha(char const *str);

void my_putchar(char c);

static int is_alphanumeric(char str)
{
    if (str >= 'A' && str <= 'Z'
        || str >= 'a' && str <= 'z'
        || str >= '0' && str <= '9') {
        return (1);
    } else
        return (0);
}

static int word_count(char const *str)
{
    int i = 0;
    int j = 0;

    for (int a = 0 ; str[a] != '\0' ; a += 1)
    {
        if (is_alphanumeric(str[a]) == 1){
            j += 1;
        } else {
            i += 1;
            j = 0;
        }
    }
    return (i + 2);
}

static int word_size(char const *str, int nb)
{
    int j = 0;

    for (int a = nb ; str[a] != '\0' ; a += 1)
    {
        if (is_alphanumeric(str[a]) == 1){
            j += 1;
        } else
            return (j + 2);
    }
    return (j + 2);
}

char **my_str_to_word_array(char const *str, char c)
{
    char **item;
    int i = 0;
    int j = 0;
    int a = 0;

    item = malloc( word_count(str) * sizeof(char *));
    item[0] = malloc(sizeof(char) * (word_size(str , 0) + 1));
    for ( a = 0 ; str[a] != '\0' ; a += 1){
        if (str[a] != c){
            item[i][j] = str[a];
            j += 1;
        } else {
            item[i][j] = '\0';
            i += 1;
            item[i] = malloc(sizeof(char) * (word_size(str , a) + 1));
            j = 0;
        }
    }
    item[i + 1] = NULL;
    return (item);
}
