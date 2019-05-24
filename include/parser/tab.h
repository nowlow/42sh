/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** tab
*/

#ifndef TAB_H_
#define TAB_H_

char **init_tab(int *tab_size);

void tab_resize(char ***tab, int *tab_size, int new_size);

void add_to_tab(char ***tab, int *tab_size, char *line);

#endif /* !TAB_H_ */
