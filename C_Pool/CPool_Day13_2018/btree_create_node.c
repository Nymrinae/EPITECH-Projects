/*
** EPITECH PROJECT, 2018
** Task01
** File description:
** btree_create_node
*/

#include <stddef.h>
#include <stdlib.h>
#include "include/my.h"
#include "include/btree.h"

btree_t *btree_create_node(void *item)
{
    btree_t *node = NULL;
    
    node = malloc(sizeof(btree_t));
    if(!node)
        return (0);
    node->left = NULL;
    node->right = NULL;
    node->item = item;
   return (item);
}
