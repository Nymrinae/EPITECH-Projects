/*
** EPITECH PROJECT, 2018
** Rush 2
** File description:
** frequence
*/

#include "my.h"

int count_letters(char *str)
{
    int i = 0;
    int l = 0;

    while (str[i]) {
        if (is_alpha(str[i]))
            ++l;
        ++i;
    }
    return (l);
}

int occurences(char *str, char c, int *freq)
{
    int i = 0;
    int occ = 0;

    if (c >= 'A' && c <= 'Z')
        c += 'a' - 'A';
    str = my_strlowcase(str);
    while(str[i]) {
        if (str[i] == c)
            ++occ;
        ++i;
    }
    *freq = (occ * 10000) / (count_letters(str));
    return (occ);
}
