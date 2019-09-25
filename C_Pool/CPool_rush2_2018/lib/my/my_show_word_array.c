/*
** EPITECH PROJECT, 2018
** showwordarray
** File description:
** showwordarray
*/

#include "my.h"

int my_show_word_array(char * const *tab)
{
    int i;

    for (i = 0; tab[i] != 0; i++) {
        my_putstr(tab[i]);
        my_putchar('\n');
    }
    return (0);
}
