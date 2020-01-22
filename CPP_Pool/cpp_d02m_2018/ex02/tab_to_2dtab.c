/*
** EPITECH PROJECT, 2018
** tab_to_2dtab.c
** File description:
** Exercise 2 - Tab To 2DTab - Pointers and Memory
*/

#include <stdlib.h>

void tab_to_2dtab(const int *tab, int length, int width, int ***res)
{
    *res = malloc(length * sizeof(int *) + 1);

    for (int i = 0; i < length; i++){
        (*res)[i] = malloc(width * sizeof(int) + 1);
        for (int j = 0; j < width; j++)
            (*res)[i][j] = tab[i * width + j];
    }
}