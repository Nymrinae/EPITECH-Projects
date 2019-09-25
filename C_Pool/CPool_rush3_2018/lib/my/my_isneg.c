/*
** EPITECH PROJECT, 2018
** my_isneg
** File description:
** This file return N or P
** if n is negative or positive
*/

void    my_putchar(char c);

int    my_isneg(int n)
{
    if (n < 0)
        my_putchar(78);
    else
        my_putchar(80);

    return (0);
}
