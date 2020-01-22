/*
** EPITECH PROJECT, 2018
** LittheHand.cpp
** File description:
** Exersice 1 - Can I have some more ?
*/

#ifndef _LITTLEHAND_H
#define _LITTLEHAND_H

#include <iostream>
#include <string>
#include "FruitBox.hpp"

class LittleHand {
    public:
        static void sortFruitBox(FruitBox &unsorted, 
                          FruitBox &lemons,
                          FruitBox &bananas,
                          FruitBox &limes);
};

#endif