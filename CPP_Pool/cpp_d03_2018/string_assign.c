/*
** EPITECH PROJECT, 2018
** string_assign.c
** File description:
** Exercise 1 - Assign
*/

#include "string.h"

void assign_s(string_t *this, const string_t *str)
{
    str ? this->str = strdup(str->str) : NULL;
}

void assign_c(string_t *this, const char *s)
{
    s ? this->str = strdup(s) : NULL;
}