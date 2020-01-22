/*
** EPITECH PROJECT, 2018
** string_find.c
** File description:
** Exercise 10 - Find
*/

#include "string.h"

int find_c(const string_t *this, const char *str, size_t pos)
{
    int this_len = strlen(this->str);
    char *isfound = strstr(this->str, str);

    return (isfound ? isfound - (this->str) : -1);
}

int find_s(const string_t *this, const string_t *str, size_t pos)
{
    return find_c(this, str->str, pos);
}