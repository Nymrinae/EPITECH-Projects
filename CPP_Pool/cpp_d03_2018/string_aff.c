/*
** EPITECH PROJECT, 2018
** string_aff.c
** File description:
** Exercise 14 - Aff
*/

#include "string.h"

void aff(const string_t *this)
{
    if (this->str)
        printf("%d\n", this->str);
}