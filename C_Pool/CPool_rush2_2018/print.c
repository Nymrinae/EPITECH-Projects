/*
** EPITECH PROJECT, 2018
** print
** File description:
** rush2
*/

#include "rush2.h"

void print_freq(int frq)
{
    int nb;

    if (frq == 10000) {
        my_putstr("100.00");
        return;
    }
    nb = (frq / 1000);
    if (nb != 0)
        my_put_nbr(nb);
    my_put_nbr((frq / 100) % 10);
    my_putchar('.');
    nb = frq % 100;
    if (nb != 0)
        my_put_nbr(frq % 100);
    else
        my_putstr("00");
}

void print_letter(int occ, char c, int freq)
{
    my_putchar(c);
    my_putchar(':');
    my_put_nbr(occ);
    my_putstr(" (");
    print_freq(freq);
    my_putstr("%)\n");
}

void print_language(struct language_points pts)
{
    int res;

    res = MAX(pts.fra, pts.eng);
    res = MAX(pts.ger, res);
    res = MAX(pts.spa, res);
    if (res == pts.fra)
        my_putstr("=> French\n");
    else if (res == pts.eng)
        my_putstr("=> English\n");
    else if (res == pts.ger)
        my_putstr("=> German\n");
    else if (res == pts.spa)
        my_putstr("=> Spanish\n");
}
