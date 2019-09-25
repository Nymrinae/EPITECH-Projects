/*
** EPITECH PROJECT, 2018
** guess_language
** File description:
** guess_language
*/

#include "rush2.h"
#include "language_const.h"

void add_point(struct language_points *points, int diff[4])
{
    int smallest_diff;

    smallest_diff = MIN(diff[0], diff[1]);
    smallest_diff = MIN(smallest_diff, diff[2]);
    smallest_diff = MIN(smallest_diff, diff[3]);
    if (smallest_diff == diff[0])
        (points->fra)++;
    else if (smallest_diff == diff[1])
        (points->eng)++;
    else if (smallest_diff == diff[2])
        (points->ger)++;
    else if (smallest_diff == diff[3])
        (points->spa)++;
}

void guess_language(char *str)
{
    int i = 0;
    int diff[4];
    int freq;
    struct language_points points = {0};

    while (i < 26) {
        occurences(str, alphabet[i], &freq);
        diff[0] = ABS(freq - fra[i]);
        diff[1] = ABS(freq - eng[i]);
        diff[2] = ABS(freq - ger[i]);
        diff[3] = ABS(freq - spa[i]);
        add_point(&points, diff);
        ++i;
    }
    print_language(points);
}
