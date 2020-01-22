/*
** EPITECH PROJECT, 2018
** ex02.cpp
** File description:
** Exersice 2 - The return of min
*/

#ifndef _TEMPLATE_H
#define _TEMPLATE_H

#include <iostream>
#include <string>

int min(int a, int b)
{
    std::cout << "non-template min" << std::endl;

    return (a <= b ? a : b);
}

template <typename T>
const T &min(const T &n1, const T &n2)
{
    std::cout << "template min" << std::endl;
    
    return (n1 <= n2 ? n1 : n2);
}

int nonTemplateMin(int *tab, int size)
{
    int val = tab[0];

    for (int i = 1; i < size; i++)
        val = min(val, tab[i]);
    
    return (val);
}

template <typename T>
const T &templateMin(const T *tab, int size)
{
    T &val = const_cast<T&>(tab[0]);

    for (int i = 1; i < size; i++)
        val = min<T>(val, tab[i]);
    
    return (val);
}

#endif