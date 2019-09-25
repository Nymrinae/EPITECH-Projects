/*
** EPITECH PROJECT, 2018
** print
** File description:
** contains print functions for rush3
*/

#include "../include/my.h"

void display(char *str, int c, int r)
{
    my_putstr(str);
    my_putchar(' ');
    my_put_nbr(c);
    my_putchar(' ');
    my_put_nbr(r);
}
