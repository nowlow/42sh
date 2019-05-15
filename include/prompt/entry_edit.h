/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** entry_edit
*/

#ifndef ENTRY_EDIT_H_
#define ENTRY_EDIT_H_

#include <stddef.h>

char *delete_one(char *str, size_t size, size_t cpos);
char *delete_all(char *str, size_t size, size_t cpos);
char *delete_from_cursor_pos(char *str, size_t size, size_t cpos);

#endif /* !ENTRY_EDIT_H_ */