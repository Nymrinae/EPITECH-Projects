/*
** EPITECH PROJECT, 2018
** menger.c
** File description:
** Exercise 1 - The Menger Sponge
*/

#include "menger.h"

int menger(int size, int level)
{
    return (level < size && size % 3 == 0
            ? do_menger(size, level, 0, 0)
            : 84);
}

void run_menger(int size, int level, int x, int y)
{
    int size_x;
    int size_y;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (i != 1 || j != 1) {
                size_x = i * (size / 3) + x;
                size_y = j * (size / 3) + y;
                do_menger((size/3), level - 1, size_x, size_y);     
            }
}

int do_menger(int size, int level, int x, int y)
{
    if (level > 0)
        printf("%03i %03i %03i\n", (size / 3), (size /3) + x, (size / 3) + y);
    if (level > 1)
        run_menger(size, level, x, y);
    return (0);
}