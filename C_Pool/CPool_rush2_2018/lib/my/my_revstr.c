/*
** EPITECH PROJECT, 2018
** revstr
** File description:
** revstr
*/

#include "my.h"

char *my_revstr(char *str)
{
    int i;
    int len = my_strlen(str);
    char c;

    for (i = 0; i < len / 2; i++) {
        c = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = c;
    }
    return (str);
}
