/*
** EPITECH PROJECT, 2018
** string_insert.c
** File description:
** Exercise 11 - Insert
*/

#include "string.h"

void insert_c(string_t *this, size_t pos, const char *str)
{
    int str_len = strlen(this->str) + strlen(str) + 1;
    char *res = malloc(str_len * sizeof(char));
    char *str_to_copy = strdup(this->str);

    if (str) {
        strncpy(res, this->str, pos);
        strcat(res, str);
        while (pos--)
            *str_to_copy++;
        strcat(res, str_to_copy);
        this->str = res;
    }
}

void insert_s(string_t *this, size_t pos, const string_t *str)
{
    return (insert_c(this, pos, str->str));
}