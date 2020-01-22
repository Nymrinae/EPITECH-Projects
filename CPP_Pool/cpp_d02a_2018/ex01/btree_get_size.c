/*
** EPITECH PROJECT, 2018
** btree_get_size.c
** File description:
** Exercise 1 - Simple Tree
*/

#include <stdlib.h>
#include "simple_btree.h"

unsigned int btree_get_size(tree_t tree)
{
    unsigned int tree_size;

    tree_size = btree_get_size(tree->left) +
                btree_get_size(tree->right) + 1;

    return (tree ? tree_size : 0);
}
