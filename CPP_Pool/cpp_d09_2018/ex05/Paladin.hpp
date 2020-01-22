/*
** EPITECH PROJECT, 2018
** Paladin.hpp
** File description:
** Exercise 4 - Paladins
*/

#ifndef _PALADIN_H
#define _PALADIN_H

#include <iostream>
#include <string>

#include "Warrior.hpp"
#include "Priest.hpp"

class Paladin : virtual public Warrior, virtual public Priest {
    protected:
        std::string _race;
    public:
        Paladin(const std::string &name, int level);
        ~Paladin() { };

        using Warrior::CloseAttack;
        using Warrior::RestorePower;
        using Priest::Heal;
        using Priest::RangeAttack;

        int Intercept();
};

#endif