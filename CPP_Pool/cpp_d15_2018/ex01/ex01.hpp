/*
** EPITECH PROJECT, 2018
** ex01.cpp
** File description:
** Exersice 1 - Compare
*/

#ifndef _TEMPLATE_H
#define _TEMPLATE_H

#include <iostream>
#include <string>
#include <cstring>

template <typename T>
int compare(const T &a, const T &b)
{
    if (a > b) 
        return (1);
    if (a < b)
        return (-1);

    return (0);
}

template<>
int compare<const char *>(const char * const &a, const char * const &b)
{
    int cmp = strcmp(a, b);

    if (cmp > 0) 
        return (1);
    if (cmp < 0)
        return (-1);

    return (0);
}

#endif