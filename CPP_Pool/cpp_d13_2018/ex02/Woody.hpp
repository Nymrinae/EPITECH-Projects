/*
** EPITECH PROJECT, 2018
** Woody.cpp
** File description:
** Exersice 2 - Simple inheritance
*/

#ifndef _WOODY_H
#define _WOODY_H

#include <iostream>
#include <string>
#include "Toy.hpp"

class Woody : public Toy {
    protected:

    public:
        // Constructor && Destructor
        Woody(std::string const &name);
        Woody(std::string const &name, std::string const &filename);
        ~Woody() { };

};

#endif

