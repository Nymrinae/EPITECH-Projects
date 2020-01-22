/*
** EPITECH PROJECT, 2018
** list_delete_elem_at_back.c
** File description:
** Exercise 0 - Simple list
*/

#include <stdlib.h>
#include "simple_list.h"

bool_t list_del_elem_at_back(list_t *front_ptr)
{
    list_t list = *front_ptr;
    list_t prev = NULL;

    if (!list)
        return (FALSE);
    while (list->next) {
        prev = list;
        list = list->next;
    }

    if (prev)
        prev->next = NULL;
    else
        *front_ptr = NULL;
    free(list);

    return (TRUE);
}
