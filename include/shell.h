/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** shell
*/

#ifndef SHELL_H_
#define SHELL_H_

#include <stdlib.h>

#define BASE_PATH "PATH=/bin:/usr/bin"
#define IS_LETTER(c) ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) ? 1 : 0
#define IS_NUMBER(n) (n >= '0' && n <= '9') ? 1 : 0
#define PROMPT "\e[1m ❯ \e[21m"

#include "utils.h"
#include "structs.h"
#include "commands.h"
#include "errors.h"
#include "paths.h"

#endif /* !SHELL_H_ */