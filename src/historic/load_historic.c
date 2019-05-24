/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** manage_list.c
*/

#include "historic.h"
#include <string.h>

// history_t *load_from_file(char *buffer, history_t *list)
// {
//     history_t *head = list;
//     char *tmp = NULL;
//     int count = 1;

//     list->number = 0;
//     list->command = strtok(buffer, "\n");
//     list->empty = true;
//     list->previous = NULL;
//     list->next = malloc(sizeof(history_t));
//     list->next->head = list;
//     list = list->next;
//     while ((tmp = strtok(buffer, "\n")) != NULL) {
//         buffer = &buffer[strlen(tmp) + (buffer[strlen(tmp)]) ? 1 : 0];
//         list->number = count;
//         list->command = tmp;
//         list->empty = true;
//         list->next = malloc(sizeof(history_t));
//         list->next->previous = list;
//         list->next->head = list->head;
//         list = list->next;
//         count += 1;
//     }
//     list->head = head;
//     return (list);
// }

// history_t *get_file_in_list(char *buffer)
// {
//     int count = 0;
//     char *tmp;
//     history_t *list = malloc(sizeof(history_t));

//     list = load_from_file(buffer, list);
//     while (list->next != NULL)
//         count += 1;
//     while (count != 100) {
//         list->number = count;
//         list->command = tmp;
//         list->empty = true;
//         list->next = malloc(sizeof(history_t));
//         list->next->previous = list;
//         list->next->head = list->head;
//         list = list->next;
//         count += 1;
//     }
//     return (list);
// }

// history_t *create_list(void)
// {
//     char *buffer = open_the_file("historic.txt");
//     int count = 1;
//     char *tmp;
//     history_t *list = malloc(sizeof(history_t));

//     if (buffer != NULL)
//         return (get_file_in_list(buffer));
//     while (count != 100) {
//         printf("coucou\n");
//         list->number = count;
//         list->command = tmp;
//         list->empty = true;
//         list->next = malloc(sizeof(history_t));
//         list->next->previous = list;
//         list->next->head = list->head;
//         list = list->next;
//         count += 1;
//     }
//     list = list->head;
//     return (list);
// }