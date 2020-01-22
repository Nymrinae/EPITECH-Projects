/*
** EPITECH PROJECT, 2019
** drawing.c
** File description:
** Exersice 3 - Draw Me a Square
*/

#include "drawing.h"

void draw_square(uint32_t **img, const point_t *origin,
                 size_t size, uint32_t color)
{       
    for (size_t i = 0; i < size; i++) {
		for (size_t j = 0; j < size; j++) {
			img[origin->x + i][origin->y + j] = color;
		}
}
}
