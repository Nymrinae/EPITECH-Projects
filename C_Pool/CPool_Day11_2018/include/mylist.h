/*
** EPITECH PROJECT, 2018
** mylist
** File description:
** header
*/

typedef struct linked_list
{
    void *data;
    struct linked_list *next;
} linked_list_t;

linked_list_t *my_params_to_list(int ac, char * const *av);

void add_to_list(linked_list_t **list, char *av);

int my_list_size(linked_list_t const *begin);
