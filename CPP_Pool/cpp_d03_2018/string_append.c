/*
** EPITECH PROJECT, 2018
** string_append.c
** File description:
** Exercise 2 - Append
*/

#include "string.h"

void append_s(string_t *this, const string_t *ap)
{
    int str_len = strlen(this->str) + strlen(ap->str) + 1;
    char *res = malloc(str_len * sizeof(char));

    if (ap->str) {
        strcat(res, this->str);
        strcat(res, ap->str);
        string_destroy(this);
        this->str = res;
    }
}

void append_c(string_t *this, const char *ap)
{
    int str_len = strlen(this->str) + strlen(ap) + 1;
    char *res = malloc(str_len * sizeof(char));

    if (ap) {
        strcat(res, this->str);
        strcat(res, ap);
        string_destroy(this);
        this->str = res;
    }
}