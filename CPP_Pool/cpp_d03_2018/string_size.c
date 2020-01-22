/*
** EPITECH PROJECT, 2018
** string_size.c
** File description:
** Exercise 5 - Size
*/

#include "string.h"

int size(const string_t *this)
{
    return (this->str ? strlen(this->str) : -1);
}