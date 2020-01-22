/*
** EPITECH PROJECT, 2018
** list_del_elem_at_front.c
** File description:
** Exercise 0 - Simple list
*/

#include <stdlib.h>
#include "simple_list.h"

bool_t list_del_elem_at_front(list_t *front_ptr)
{
    list_t list = *front_ptr;

    if (!list)
        return (FALSE);
    (*front_ptr) = list->next;
    free(list);

    return (TRUE);
}
