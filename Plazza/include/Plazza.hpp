/*
** EPITECH PROJECT, 2019
** Plazza
** File description:
** 
*/

#ifndef _PLAZZA_H
#define _PLAZZA_H

#include <map>
#include <array>
#include <tuple>
#include <cctype>
#include <thread>
#include <vector>
#include <string>
#include <fcntl.h>
#include <iostream>
#include <unistd.h>
#include <algorithm>
#include <sys/wait.h>
#include <sys/mman.h>

enum PizzaType
{
    Regina = 1,
    Margarita = 2,
    Americana = 4,
    Fantasia = 8
};

enum PizzaSize
{
    S = 1,
    M = 2,  
    L = 4,
    XL = 8,
    XXL = 16
};

void displayUsage();
bool areArgumentsValid(int, char const * const *);

#endif