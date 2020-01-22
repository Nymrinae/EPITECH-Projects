/*
** EPITECH PROJECT, 2018
** Lemon.cpp
** File description:
** Exersice 0 - Fruits
*/

#ifndef _LEMON_H
#define _LEMON_H

#include <iostream>
#include <string>
#include "Fruit.hpp"

class Lemon : public Fruit {
    public:
        Lemon();
        Lemon(Lemon const &Lemon);
        ~Lemon() { };
        Lemon &operator=(Lemon const &Lemon);

        virtual std::string getName() const;
        virtual int getVitamins() const;
};

#endif

