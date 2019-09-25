/*
** EPITECH PROJECT, 2018
** Task 02
** File description:
** my_list_size
*/

#include "include/my.h"
#include "include/mylist.h"
#include <stdlib.h>

int my_list_size(linked_list_t const *begin)
{
    linked_list_t const *tmp;
    int i = 0;
    
    tmp = begin;
    while (tmp != NULL) {
        i++;
        tmp = tmp->next;
    }

    return (i);
}
