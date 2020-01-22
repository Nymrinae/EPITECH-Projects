/*
** EPITECH PROJECT, 2018
** Banana.cpp
** File description:
** Exersice 0 - Fruits
*/

#ifndef _BANANA_H
#define _BANANA_H

#include <iostream>
#include <string>
#include "Fruit.hpp"

class Banana : public Fruit {
    public:
        Banana();
        Banana(Banana const &Banana);
        ~Banana() { };
        Banana &operator=(Banana const &Banana);

        virtual std::string getName() const;
        virtual int getVitamins() const;
};

#endif

