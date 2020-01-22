/*
** EPITECH PROJECT, 2018
** string_clear.c
** File description:
** Exercise 4 - Clear
*/

#include "string.h"

void clear(string_t *this)
{
    char *end = "\0";

    if (this->str)
        this->str = strdup(end);
}