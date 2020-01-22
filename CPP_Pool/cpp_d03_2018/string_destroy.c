/*
** EPITECH PROJECT, 2018
** string_destroy.c
** File description:
** Exercise 0 - My String
*/

#include "string.h"

void string_destroy(string_t *this)
{
    if (this->str)
        free(this->str);
}