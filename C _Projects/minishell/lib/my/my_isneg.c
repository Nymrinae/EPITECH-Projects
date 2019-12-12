/*
** EPITECH PROJECT, 2018
** MY_ISNEG
** File description:
** Displays either N if the integer is negative, P if positive or null.
*/

#include "my.h"

int my_isneg(int n)
{
    if (n < 0)
        my_putchar('N');
    else
        my_putchar('P');

    my_putchar('\n');
}
