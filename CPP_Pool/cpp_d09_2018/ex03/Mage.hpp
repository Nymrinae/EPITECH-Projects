/*
** EPITECH PROJECT, 2018
** Mage.hpp
** File description:
** Exercise 3 - Children
*/

#ifndef _MAGE_H
#define _MAGE_H

#include <iostream>
#include <string>

#include "Character.hpp"

class Mage : public Character {
    protected:
        std::string _race;
        int         _spirit;
    public:
        Mage(const std::string &name, int level);
        ~Mage() { };

        int     CloseAttack();
        int     RangeAttack();
        void    RestorePower();
};

#endif