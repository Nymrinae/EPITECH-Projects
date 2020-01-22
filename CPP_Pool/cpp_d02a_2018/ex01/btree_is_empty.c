/*
** EPITECH PROJECT, 2018
** btree_is_empty.c
** File description:
** Exercise 1 - Simple Tree
*/

#include <stdlib.h>
#include "simple_btree.h"

bool_t btree_is_empty(tree_t tree)
{
    return (tree == NULL ? TRUE : FALSE);
}
