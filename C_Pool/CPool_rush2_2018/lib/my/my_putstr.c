/*
** EPITECH PROJECT, 2018
** putstr
** File description:
** putstr
*/

#include "my.h"

int my_putstr(char const *str)
{
    int cur;

    for (cur = 0; str[cur] != '\0'; cur++)
        my_putchar(str[cur]);
    return (0);
}
