/*
** EPITECH PROJECT, 2018
** list_add_elem_at_back.c
** File description:
** Exercise 0 - Simple list
*/

#include <stdlib.h>
#include "simple_list.h"

bool_t list_add_elem_at_back(list_t *front_ptr, double elem)
{
    list_t node = malloc(sizeof(list_t));
    list_t list = *front_ptr;

    if (!node)
        return (FALSE);
    node->value = elem;
    node->next = NULL;

    if (!list)
        *front_ptr = node;
    else {
        list = *front_ptr;
        while (list->next)
            list = list->next;
        list->next = node;
    }
    return (TRUE);
}