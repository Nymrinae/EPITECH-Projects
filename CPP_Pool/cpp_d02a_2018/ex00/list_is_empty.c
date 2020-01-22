/*
** EPITECH PROJECT, 2018
** list_is_empty.c
** File description:
** Exercise 0 - Simple list
*/

#include <stdlib.h>
#include "simple_list.h"

bool_t list_is_empty(list_t list)
{
    return (list == NULL ? TRUE : FALSE);
}