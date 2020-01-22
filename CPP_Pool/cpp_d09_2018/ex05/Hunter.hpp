/*
** EPITECH PROJECT, 2018
** Hunter.hpp
** File description:
** Exercise 5 - Or is it 11 ?
*/

#ifndef _HUNTER_H
#define _HUNTER_H

#include <iostream>
#include <string>

#include "Warrior.hpp"

class Hunter : virtual public Warrior {
    protected:
        std::string _race;
        int         _spirit;

    public:
        Hunter(const std::string &name, int level);
        ~Hunter() { };

        int     RangeAttack();
        void    RestorePower();
        using   Warrior::CloseAttack;
        using   Warrior::Heal;
};

#endif