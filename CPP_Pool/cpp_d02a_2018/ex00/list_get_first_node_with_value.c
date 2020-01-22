/*
** EPITECH PROJECT, 2018
** list_get_first_node_with_value.c
** File description:
** Exercise 0 - Simple list
*/

#include <stdlib.h>
#include "simple_list.h"

node_t *list_get_first_node_with_value(list_t list, double value)
{
    while (list != NULL) {
        if (list->value == value)
            return (list);
        list = list->next;
    }

    return (NULL);
}