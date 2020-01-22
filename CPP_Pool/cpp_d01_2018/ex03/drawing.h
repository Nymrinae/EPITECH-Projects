/*
** EPITECH PROJECT, 2019
** drawing.h
** File description:
** Exersice 3 - Draw Me a Square
*/

#ifndef __DRAWING_H_
#define __DRAWING_H_

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct point {
    uint32_t x;
    uint32_t y;
} point_t;

void draw_square(uint32_t **img, const point_t *origin,
                 size_t size, uint32_t color);

#endif