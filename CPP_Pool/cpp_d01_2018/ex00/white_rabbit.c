/*
** EPITECH PROJECT, 2018
** white_rabbit.c
** File description:
** Exercise 0 - Follow The White Rabbit
*/

#include <stdio.h>
#include <stdlib.h>

int follow_the_white_rabbit(void)
{
    int total = 0;
    int c = 0;
    int bite = 1;

    while (bite) {
        c = (random() % 37) + 1;
        total += c;
        if (c == 1 || c == 37 || total >= 397) {
            printf("RABBIT!!!\n");
            break;
        }
        if ((c >= 4 && c <= 6) || (c >= 17 && c <= 21) || c == 28)
            printf("left\n");
        if (c == 13 || c >= 34)
            printf("right\n");
        if (c == 10 || c == 15 || c == 23)
            printf("forward\n");
        if ((c % 8 == 0) || (3 * c == 78))
            printf("backward\n");
    }
    return (total);
}