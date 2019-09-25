/*
** EPITECH PROJECT, 2018
** my_swap
** File description:
** This fonction swap the content of two integers
*/

void    my_swap(int *a, int *b)
{
    int c = *a;
    *a = *b;
    *b = c;
}