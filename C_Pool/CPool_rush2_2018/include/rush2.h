/*
** EPITECH PROJECT, 2018
** rush2 header
** File description:
** prototypes
*/

#ifndef _RUSH2_H_
#define _RUSH2_H_

#include "my.h"

#define ABS(x) (x > 0) ? (x) : (x * -1)
#define MAX(x, y) (y > x) ? y : x;
#define	MIN(x, y) (y < x) ? y : x;

struct language_points {
    int fra;
    int eng;
    int ger;
    int spa;
};

int occurences(char *, char, int *);
void print_letter(int, char, int);
void print_language(struct language_points);
void guess_language(char *);

#endif
