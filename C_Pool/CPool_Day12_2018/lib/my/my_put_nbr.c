/*
** EPITECH PROJECT, 2018
** my_put_nbr
** File description:
** Displays the number given as a parameter
*/

#include <unistd.h>
#include "../../include/my.h"

int my_put_nbr(int n)
{
    char digit;

    if (n < 0) {
        my_putchar('-');
        n *= -1;
    }
    if (n >= 10) {
       digit = n % 10;
       n = (n - digit) / 10;
       my_put_nbr(n);
       my_putchar(48 + digit);
    }
    else
        my_putchar(48 + n % 10);
    return (0);
}
