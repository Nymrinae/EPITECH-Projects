/*
** EPITECH PROJECT, 2018
** string_compare.c
** File description:
** Exercise 6 - Compare
*/

#include "string.h"

int compare_s(const string_t *this, const string_t *str)
{
    return (strcmp(this->str, str->str));
}

int compare_c(const string_t *this, const char *str)
{
    return (strcmp(this->str, str));
}