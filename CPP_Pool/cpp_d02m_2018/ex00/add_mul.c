/*
** EPITECH PROJECT, 2018
** add_mul.c
** File description:
** Exercise 0 - Add Mul - Basic Pointers
*/

#include <stdio.h>

void add_mul_4param(int first, int second, int *sum, int *product)
{
    *sum = first + second;
    *product = first * second;
}

void add_mul_2param(int *first, int *second)
{
    *first = *first + *second;
    *second = (*first - *second) * *second;
}