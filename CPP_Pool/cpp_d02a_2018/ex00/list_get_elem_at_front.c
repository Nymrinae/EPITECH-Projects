/*
** EPITECH PROJECT, 2018
** list_get_elem_at_front.c
** File description:
** Exercise 0 - Simple list
*/

#include <stdlib.h>
#include "simple_list.h"

double list_get_elem_at_front(list_t list)
{
    return (!list ? 0 : list->value);
}