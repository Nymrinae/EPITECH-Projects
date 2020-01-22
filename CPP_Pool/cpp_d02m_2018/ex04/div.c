/*
** EPITECH PROJECT, 2018
** div.c
** File description:
** Exercise 4 - Cast Mania
*/

#include "castmania.h"

int integer_div(int a, int b)
{
    return (b ? a / b : 0);
}

float decimale_div(int a, int b)
{
    return (b ? ((float)a) / b : 0);
}

void exec_div(division_t *operation)
{
    int int_a = ((integer_op_t *)operation->div_op)->a;
    int int_b = ((integer_op_t *)operation->div_op)->b;
    int dec_a = ((decimale_op_t *)operation->div_op)->a;
    int dec_b = ((decimale_op_t *)operation->div_op)->b;

    if (operation->div_type == INTEGER)
        ((integer_op_t *)operation->div_op)->res =
            integer_div(int_a, int_b);
    else if (operation->div_type == DECIMALE)
        ((decimale_op_t *)operation->div_op)->res =
            decimale_div(dec_a, dec_b);
}