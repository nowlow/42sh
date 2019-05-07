/*
** EPITECH PROJECT, 2018
** getnextline_test
** File description:
** get_next_line
*/

#ifndef GET_NEXT_LINE_H_
#define GET_NEXT_LINE_H_

#ifndef READ_SIZE
    #define READ_SIZE 1
#endif

#define IS_CORRECT(rest) if(!rest) return NULL

char *get_next_line(int fd);

#endif /* !GET_NEXT_LINE_H_ */