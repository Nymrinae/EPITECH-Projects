/*
** EPITECH PROJECT, 2018
** MY_PUT_NBR
** File description:
** Write numbers.
*/

#include "my.h"

int my_put_nbr(int nb)
{
    int begin;
    int end;

    if (nb < 0)
    {
        my_putchar('-');
        my_put_nbr(-nb);
    }
    else
    {
        end = nb % 10;
        begin = nb / 10;
        if (begin != 0)
        {
            my_put_nbr(begin);
        }
        my_putchar(end + '0');
    }
    return (0);
}
