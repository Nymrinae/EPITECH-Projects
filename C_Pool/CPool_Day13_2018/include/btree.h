/*
** EPITECH PROJECT, 2018
** btree
** File description:
** btree header
*/

typedef struct btree
{
    struct btree *left;
    struct btree *right;
    void *item;
} btree_t;
