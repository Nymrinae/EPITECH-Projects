/*
** EPITECH PROJECT, 2018
** putchar
** File description:
** putchar
*/

#include "my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}
