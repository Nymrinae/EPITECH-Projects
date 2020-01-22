/*
** EPITECH PROJECT, 2018
** list_add_elem_at_front.c
** File description:
** Exercise 0 - Simple list
*/

#include <stdlib.h>
#include "simple_list.h"

bool_t list_add_elem_at_front(list_t *front_ptr, double elem)
{
    list_t current = malloc(sizeof(list_t));

    if (!current)
        return (FALSE);

    current->value = elem;
    current->next = *front_ptr;
    *front_ptr = current;

    return (TRUE);
}