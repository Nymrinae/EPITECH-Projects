/*
** EPITECH PROJECT, 2018
** MY_PUTSTR
** File description:
** Displays one-by-one the characters of a string.
*/

#include "my.h"

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
}
