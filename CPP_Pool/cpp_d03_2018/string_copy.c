/*
** EPITECH PROJECT, 2018
** string_copy.c
** File description:
** Exercise 7 - Copy
*/

#include "string.h"

size_t copy(const string_t *this, char *s, size_t n, size_t pos)
{
    int i = 0;
    int total_len = strlen(this->str) + strlen(s) + 1;

    s = malloc(total_len * sizeof(char));
    while (n-- && pos < strlen(this->str)) {
        strncat(s, &this->str[pos], 1);
        i++;
        pos++;
    }
    return (i);
}