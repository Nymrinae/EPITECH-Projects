/*
** EPITECH PROJECT, 2018
** list_get_elem_at_position.c
** File description:
** Exercise 0 - Simple list
*/

#include <stdlib.h>
#include "simple_list.h"

double list_get_elem_at_position(list_t list, unsigned int position)
{
    if (!list)
        return (0);
    while (position--) {
        list = list->next;
        if (!list)
            return (0);
    }

    return (list->value);
}