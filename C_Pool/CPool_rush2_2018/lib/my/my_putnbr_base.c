/*
** EPITECH PROJECT, 2018
** putnbrbase
** File description:
** putnbrbase
*/

#include "my.h"

static void putnbr_base_rec(int nbr, char const *base, int r, int len)
{
    if (nbr != 0)
        putnbr_base_rec(nbr / len, base, nbr % len, len);
    write(1, &(base[r]), 1);
}

int my_putnbr_base(int nbr, char const *base)
{
    int len = my_strlen(base);

    if (nbr < 0) {
        write(1, "-", 1);
        nbr *= -1;
    }
    putnbr_base_rec(nbr / len, base, nbr % len, len);
    return (0);    
}
