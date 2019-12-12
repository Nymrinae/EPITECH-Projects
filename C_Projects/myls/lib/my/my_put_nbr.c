/*
** EPITECH PROJECT, 2018
** my_put_nbr
** File description:
** This file print a number
*/

void    my_putchar(char c);
int    if_positive(long a);

int    my_put_nbr(int nb)
{
    if (nb > 0) {
        if_positive((long)nb);
    }
    if (nb < 0) {
        nb *= -1;
        my_putchar('-');
        if_positive((long)nb);
    }
    if (nb == 0)
        my_putchar('0');
    return (0);
}

int    if_positive(long a)
{
    if (a <= 9) {
        my_putchar(a + '0');
    } else {
        if_positive(a/10);
        my_putchar(a%10 + '0');
    }
    return (0);
}