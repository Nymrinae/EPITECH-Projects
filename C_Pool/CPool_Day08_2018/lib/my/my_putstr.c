/*
** EPITECH PROJECT, 2018
** my_putstr
** File description:
** Print one string
*/

#include <unistd.h>
#include "include/my.h"

int my_putstr(char const *str)
{
    write(1, str, my_strlen(str) + 1);
    return (0);
}
