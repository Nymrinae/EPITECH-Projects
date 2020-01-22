/*
** EPITECH PROJECT, 2018
** ex04.cpp
** File description:
** Exersice 4 - Testing
*/

#ifndef _TEMPLATE_H
#define _TEMPLATE_H

#include <iostream>
#include <string>

template <typename T>
bool equal(const T &a, const T &b)
{
    return (a == b);
}

template <typename T>
class Tester {
    public:
        Tester() { };
        ~Tester() { };
        bool equal(const T &a, const T &b)
        {
            return (a == b);
        };

};

#endif