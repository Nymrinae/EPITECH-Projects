/*
** EPITECH PROJECT, 2018
** ex03.cpp
** File description:
** Exersice 3 - Another iteration
*/

#ifndef _TEMPLATE_H
#define _TEMPLATE_H

#include <iostream>
#include <string>

template <typename T>
void foreach(const T *tab, void(func)(const T&), int size)
{
    for (int i = 0; i < size; i++)
        (*func)(tab[i]);
}

template <typename T>
void print(const T &a)
{
    std::cout << a << std::endl;
}

#endif