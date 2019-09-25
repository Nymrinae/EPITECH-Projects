/*
** EPITECH PROJECT, 2018
** putnbr
** File description:
** putnbr
*/

#include "my.h"

static void print_min(void)
{
    my_putchar('-');
    my_putchar('2');
    my_putchar('1');
    my_putchar('4');
    my_putchar('7');
    my_putchar('4');
    my_putchar('8');
    my_putchar('3');
    my_putchar('6');
    my_putchar('4');
    my_putchar('8');
}

static void rec_print(int nb)
{
    if (nb > 9)
        rec_print(nb / 10);
    my_putchar(nb % 10 + '0');
}

int my_put_nbr(int nb)
{
    if (nb == INT_MIN) {
        print_min();
        return (0);
    }
    if (nb < 0) {
        nb *= -1;
        my_putchar('-');
    }
    rec_print(nb);
    return (0);
}
