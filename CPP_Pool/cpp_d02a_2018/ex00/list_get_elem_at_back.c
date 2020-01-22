/*
** EPITECH PROJECT, 2018
** list_get_elem_at_back.c
** File description:
** Exercise 0 - Simple list
*/

#include <stdlib.h>
#include "simple_list.h"

double list_get_elem_at_back(list_t list)
{
    if (!list)
        return (0);
    while (list->next)
        list = list->next;

    return (list->value);
}