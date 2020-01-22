/*
** EPITECH PROJECT, 2018
** list_del_elem_at_position.c
** File description:
** Exercise 0 - Simple list
*/

#include <stdlib.h>
#include "simple_list.h"

bool_t list_del_elem_at_position(list_t *front_ptr, unsigned int position)
{
    list_t prev = *front_ptr;
    list_t list = prev->next;

    if (position == 0)
        return (list_del_elem_at_front(front_ptr));
    if (!front_ptr)
        return (FALSE);
    while (--position) {
        if (!list)
            return (FALSE);
        prev = list;
        list = list->next;
    }
    if (list)
        prev->next = list->next;
    free(list);

    return (TRUE);
}
