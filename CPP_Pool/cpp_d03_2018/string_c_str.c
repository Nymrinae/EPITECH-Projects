/*
** EPITECH PROJECT, 2018
** string_c_str.c
** File description:
** Exercise 8 - C_str
*/

#include "string.h"

const char *c_str(const string_t *this)
{
    if (this->str)
        return (this->str);
}