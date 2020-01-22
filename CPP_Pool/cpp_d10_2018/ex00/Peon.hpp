/*
** EPITECH PROJECT, 2018
** Peon.hpp
** File description:
** Exercise 0 - Ponymorphism
*/

#ifndef _PEON_H
#define _PEON_H

#include <iostream>
#include <string>
#include "Victim.hpp"

class Peon : public Victim {
    protected:
        std::string _name;
    public:
        Peon(const std::string &name);
        ~Peon();

        virtual void getPolymorphed() const;
};

#endif