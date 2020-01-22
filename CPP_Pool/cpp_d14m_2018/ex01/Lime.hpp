/*
** EPITECH PROJECT, 2018
** Banana.cpp
** File description:
** Exersice 0 - Fruits
*/

#ifndef LIME_H
#define LIME_H

#include "Lemon.hpp"

class Lime : public Lemon {
    public:
    Lime();
    Lime(Lime const&);
    Lime& operator=(Lime const&);
    virtual ~Lime() { };

    virtual std::string  getName() const { return (this->_name); };
    virtual int          getVitamins() const { return (this->_vitamins); };
};

#endif
