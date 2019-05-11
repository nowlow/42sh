/*
** EPITECH PROJECT, 2019
** prompt
** File description:
** keys
*/

#ifndef KEYS_H_
#define KEYS_H_

#define UP_ARROW -1
#define LEFT_ARROW -2
#define DOWN_ARROW -3
#define RIGHT_ARROW -4
#define INVERTED_TAB -5

char special_keys_code[][4] =
{
    {27, 91, 65},
    {27, 91, 68},
    {27, 91, 66},
    {27, 91, 67},
    {27, 91, 90},
    {0, 0, 0}
};

char special_keys[][1] =
{
    -1, -2, -3, -4, -5
};

#endif /* !KEYS_H_ */