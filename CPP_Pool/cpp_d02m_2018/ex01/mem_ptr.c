/*
** EPITECH PROJECT, 2018
** mem_ptr.c
** File description:
** Exercise 1 - Mem Ptr - Pointers and Memory
*/

#include <string.h>
#include <stdlib.h>
#include "mem_ptr.h"

void add_str(const char *str1, const char *str2, char **res)
{
    int res_len = strlen(str1) + strlen(str2) + 1;

    if (str1 || str2) {
        *res = malloc(res_len);
        strcat(*res, str1);
        strcat(*res, str2);
    } else
        *res = NULL;
}

void add_str_struct(str_op_t *str_op)
{
    char *res;

    add_str(str_op->str1, str_op->str2, &res);
    str_op->res = res;
}