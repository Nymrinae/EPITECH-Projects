/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** Exercise 1 - The Menger Sponge
*/

#include "menger.h"

int main(int ac, char **av)
{
    return (ac == 3 ? menger(my_atoi(av[1]), my_atoi(av[2]))
                    : 84);
}

int my_atoi(char *str)
{
    int res = 0;

    for (int i = 0; str[i]; i++)
        res = res * 10 + str[i] - 48;

    return (res);
}