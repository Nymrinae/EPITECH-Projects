/*
** EPITECH PROJECT, 2018
** Fruit.cpp
** File description:
** Exersice 0 - Fruits
*/

#ifndef _FRUIT_H
#define _FRUIT_H

#include <iostream>
#include <string>

class Fruit {
    protected:
        int         _vitamins;
        std::string _name;

    public:
        Fruit() { };
        Fruit(Fruit const &Fruit);
        Fruit(int vitamins, const std::string &name);
        virtual ~Fruit() { };
        Fruit& operator=(const Fruit&);

        virtual std::string getName() const = 0;
        virtual int         getVitamins() const = 0;
};

#endif

