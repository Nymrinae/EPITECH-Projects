/*
** EPITECH PROJECT, 2018
** Warrior.hpp
** File description:
** Exercise 2 - Existentialism
*/

#ifndef _WARRIOR_H
#define _WARRIOR_H

#include <iostream>
#include <string>

#include "Character.hpp"

class Warrior : public Character {
    protected:
        std::string _weaponName;
        std::string _race;
    public:
        Warrior(const std::string &name, int level);
        ~Warrior() { };

        int CloseAttack();
        int RangeAttack();
};

#endif