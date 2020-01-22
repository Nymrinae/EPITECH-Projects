/*
** EPITECH PROJECT, 2018
** list_add_elem_at_position.c
** File description:
** Exercise 0 - Simple list
*/

#include <stdlib.h>
#include "simple_list.h"

bool_t list_add_elem_at_position(list_t *front_ptr, double elem,
                                                    unsigned int position)
{
    list_t list = *front_ptr;
    list_t node = malloc(sizeof(list_t));

    if (position == 0)
        return (list_add_elem_at_front(front_ptr, elem));
    if (!front_ptr || !node)
        return (FALSE);

    while (--position) {
        list = list ->next;
        if (!list)
            return (FALSE);
    }
    node->value = elem;
    node->next = list->next;
    list->next = node;
    return (TRUE);


}
