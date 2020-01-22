/*
** EPITECH PROJECT, 2018
** Buzz.cpp
** File description:
** Exersice 2 - Simple inheritance
*/

#ifndef _BUZZ_H
#define _BUZZ_H

#include <iostream>
#include <string>
#include "Toy.hpp"

class Buzz : public Toy {
    protected:

    public:
        // Constructor && Destructor
        Buzz(std::string const &name);
        Buzz(std::string const &name, std::string const &filename);
        ~Buzz() { };

        virtual void speak(const std::string msg);
};

#endif



