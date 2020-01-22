/*
** EPITECH PROJECT, 2018
** string_to_int.c
** File description:
** Exercise 12 : To_Int
*/

#include "string.h"

int to_int(const string_t *this)
{
    if (this->str)
        return (atoi(this->str));
}