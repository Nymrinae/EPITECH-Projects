/*
** EPITECH PROJECT, 2018
** FruitNode.cpp
** File description:
** Exersice 0 - Fruits
*/

#ifndef _FRUITNODE_H
#define _FRUITNODE_H

#include <iostream>
#include <string>
#include "Fruit.hpp"

struct FruitNode 
{
    Fruit *_fruit;
    FruitNode* next;
};

#endif