/*
** EPITECH PROJECT, 2018
** ex00.cpp
** File description:
** Exersice 0 - Find me that
*/

#ifndef _FIND_H
#define _FIND_H

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

template <typename T>
typename T::iterator do_find(T &c, int x)
{
    return(std::find(c.begin(), c.end(), x));
};

#endif