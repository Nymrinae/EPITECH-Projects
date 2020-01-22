/*
** EPITECH PROJECT, 2018
** FruitBox.cpp
** File description:
** Exersice 0 - Fruits
*/

#ifndef _FRUITBOX_H
#define _FRUITBOX_H

#include <iostream>
#include <string>
#include "Fruit.hpp"
#include "FruitNode.hpp"

class FruitBox {
    protected:
        int _size;
        int _nbfruits;
        FruitNode *_list;

    public:
        FruitBox(int size);
        ~FruitBox() { };

        int nbFruits() const;
        bool putFruit(Fruit *f);
        Fruit *pickFruit();
        FruitNode *head();
};

#endif

