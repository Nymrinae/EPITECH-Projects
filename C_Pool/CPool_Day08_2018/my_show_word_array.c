/*
** EPITECH PROJECT, 2018
** my_show_word_array
** File description:
** Display the contents of an array of words
*/

#include "include/my.h"

int my_show_word_array(char * const *tab)
{
    int i = 0;

    while (tab[i]) {
        my_putstr(tab[i]);
        my_putchar('\n');
        i++;
    }
    return (0);
}
