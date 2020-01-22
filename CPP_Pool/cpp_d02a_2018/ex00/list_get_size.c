/*
** EPITECH PROJECT, 2018
** list_get_size.c
** File description:
** Exercise 0 - Simple list
*/

#include <stdlib.h>
#include "simple_list.h"

unsigned int list_get_size(list_t list)
{
    node_t *curr = list;
    unsigned int c = 0;

    while (curr != NULL){
        c++;
        curr = curr->next;
    }
    return (c);
}