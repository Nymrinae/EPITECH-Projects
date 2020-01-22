/*
** EPITECH PROJECT, 2018
** ex00.cpp
** File description:
** Exersice 0 - Old Friends
*/

#ifndef _TEMPLATE_H
#define _TEMPLATE_H

#include <iostream>
#include <string>

template <typename T>
void swap(T&a, T&b)
{
    T temp = a;
    a  = b;
    b = temp;
}

template <typename T>
const T &min(T const &n1, T const &n2)
{
    return (n1 < n2 ? n1 : n2);
}

template <typename T>
const T &max(T const &n1, T const &n2)
{
    return (n1 > n2 ? n1 : n2);
}

template <typename T>
const T add(T const &n1, T const &n2)
{
    return (n1 + n2);
}


#endif