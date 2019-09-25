/*
** EPITECH PROJECT, 2018
** my_isneg
** File description:
** Displays either N or P depending of the integer
*/

#include <unistd.h>
#include "include/my.h"

int my_isneg(int n)
{
    (n >= 0) ? my_putchar('P') : my_putchar('N');
    return (0);
}
