/*
** EPITECH PROJECT, 2018
** list_dump.c
** File description:
** Exercise 0 - Simple list
*/

#include <stdlib.h>
#include <stdio.h>
#include "simple_list.h"

void list_dump(list_t list)
{
    while (list != NULL) {
        printf("%f\n", list->value);
        list = list->next;
    }
}