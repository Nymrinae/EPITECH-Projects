/*
** EPITECH PROJECT, 2018
** string_empty.c
** File description:
** Exercise 8 - Empty
*/

#include "string.h"

int empty(const string_t *this)
{
    return (strlen(this->str) > 0 ? 1 : 0);
}