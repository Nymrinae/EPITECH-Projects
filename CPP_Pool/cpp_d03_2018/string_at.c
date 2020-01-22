/*
** EPITECH PROJECT, 2018
** string_at.c
** File description:
** Exercise 3 - At
*/

#include "string.h"

char at(const string_t *this, size_t pos)
{
    size_t len = strlen(this->str);
    return (pos < len ? (this->str)[pos] : -1);
}