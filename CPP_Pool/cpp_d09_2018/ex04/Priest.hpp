/*
** EPITECH PROJECT, 2018
** Priest.hpp
** File description:
** Exercise 3 - Children
*/

#ifndef _PRIEST_H
#define _PRIEST_H

#include <iostream>
#include <string>

#include "Mage.hpp"

class Priest : public Mage {
    protected:
        std::string _race;
    public:
        Priest(const std::string &name, int level);
        ~Priest() { };

        int CloseAttack();
        void Heal();
};

#endif