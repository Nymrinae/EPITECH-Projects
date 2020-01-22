/*
** EPITECH PROJECT, 2018
** SuperMutant.cpp
** File description:
** Exercise 1 - Let them burn
*/

#ifndef _SUPERMUTANT_H
#define _SUPERMUTANT_H

#include <iostream>
#include <string>

#include "AEnemy.hpp"

class SuperMutant : public AEnemy {
    protected:

    public:
        SuperMutant();
        ~SuperMutant();
        
        void takeDamage(int damage);
};

#endif