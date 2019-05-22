/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** entry_edit
*/

#ifndef ENTRY_EDIT_H_
#define ENTRY_EDIT_H_

#include <stddef.h>
#include "prompt.h"

char *delete_one(char *str, size_t size, cpos_t *pos);
char *delete_all(char *str, size_t size, cpos_t *pos);
char *delete_from_cursor_pos(char *str, size_t size, cpos_t *pos);

#endif /* !ENTRY_EDIT_H_ */