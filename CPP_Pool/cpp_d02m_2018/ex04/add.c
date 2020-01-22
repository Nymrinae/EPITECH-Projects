/*
** EPITECH PROJECT, 2018
** add.c
** File description:
** Exercise 4 - Cast Mania
*/

#include <stdio.h>
#include <stdlib.h>
#include "castmania.h"

int normal_add(int a, int b)
{
    return (a + b);
}

int absolute_add(int a, int b)
{
    a = (a < 0) ? -a : a;
    b = (b < 0) ? -b : b;

    return (a + b);
}

void exec_add(addition_t *operation)
{
    int a = operation->add_op.a;
    int b = operation->add_op.b;

    if (operation->add_type == NORMAL)
        operation->add_op.res = normal_add(a, b);
    else if (operation->add_type == ABSOLUTE)
        operation->add_op.res = absolute_add(a, b);

}