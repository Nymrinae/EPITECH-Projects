/*
** EPITECH PROJECT, 2018
** my_params_to_list
** File description:
** linked lists
*/

#include <stdlib.h>
#include "include/my.h"
#include "include/mylist.h"

void add_to_list(linked_list_t **list, char *av)
{
    linked_list_t *element;
    
    element = malloc(sizeof(*element));
    element->data = av;
    element->next = *list;
    *list = element;
}

linked_list_t *my_params_to_list(int ac, char * const *av)
{
    linked_list_t *list = NULL;

    for(int i = 0; i < ac; i++)
        add_to_list(&list, av[i]);

    return (list);
}
