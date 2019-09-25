/*
** EPITECH PROJECT, 2018
** showstr
** File description:
** showstr
*/

#include "my.h"

static void print_non_printable(int nb)
{
    char base[17] = "0123456789ABCDEF";

    write(1, "\\", 1);
    my_putnbr_base(nb, base);
}

int my_showstr(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= ' ' && str[i] <= '~')
            write(1, &(str[i]), 1);
        else
            print_non_printable(str[i]);
    }
    return (0);
}
