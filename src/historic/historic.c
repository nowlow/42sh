/*
** EPITECH PROJECT, 2018
** Untitled (Workspace)
** File description:
** main.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "historic.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>

void create_file(void)
{
    int fd;
    FILE *file = fopen("historic.txt", "wxr");
    fclose(file);
}

char *open_the_file(char const *filepath)
{
    struct stat buf;
    int fd;
    long long len_max;
    char *buffer;

    fd = open(filepath, O_RDONLY);
    if (stat(filepath, &buf) == -1)
        return NULL;
    len_max = buf.st_size;
    buffer = malloc(sizeof(char) * (len_max + 1));
    if (!buffer)
        return NULL;
    read(fd, buffer, len_max);
    buffer[len_max] = '\0';
    close(fd);
    return (buffer);
}

void add_to_buffer(char *command)
{
    char *buffer = open_the_file("historic.txt");
    FILE *file = fopen("historic.txt", "wr");

    buffer = strcat(buffer, command);
    fprintf(file, "%s\n", buffer);
    fclose(file);
}

// history_t *add_to_historic(char *command, history_t *list)
// {
//     add_to_buffer(command);
//     while (list->empty == false && list->number < 99)
//         list = list->next;
//     if (list->empty == true && list->number < 99) {
//         list->command = command;
//         list->empty = false;
//     }
//     if (list->number == 99) {
//         list = manage_linked_list(list);
//     }
//     return (list);
// }

// void print_list(history_t *list)
// {
//     list = list->head;

//     while (list->empty == false) {
//         printf("list number : %d command : %s\n", list->number, list->command);
//         list = list->next;
//     }
// }

// history_t *print_historic(history_t *list, int nbr)
// {
//     if (nbr == 1) {
//         if (list &&
//         list->number < 98 &&
//         list->next->command != NULL)
//             return (list->next);
//         else
//             return (list);
//     }
//     else {
//         if (list->number > 1)
//             return (list->previous);
//         else
//             return (list->head);
//     }
//     return (list);
// }

// int main (void)
// {
//     char *command = NULL;
//     char *prompt = "PROMPT ->";
//     history_t *list = create_list();

//     while (1) {
//         my_putstr(prompt);
//         command = get_next_line(0);
//         if (command[0] == 'h')
//             list = print_historic(list, 1);
//         else if (command[0] == 'd')
//             list = print_historic(list, 0);
//         else
//             list = add_to_historic(command, list);
//     }
//     return (0);
// }