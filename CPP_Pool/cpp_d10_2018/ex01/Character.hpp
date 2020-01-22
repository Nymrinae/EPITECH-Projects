/*
** EPITECH PROJECT, 2018
** Character.cpp
** File description:
** Exercise 1 - Let them burn
*/

#ifndef _CHARACTER_H
#define _CHARACTER_H

#include <iostream>
#include <string>

#include "AWeapon.hpp"
#include "AEnemy.hpp"

class Character {
    protected:
        std::string _name;
        int _ap;
        AWeapon *_weapon;

    public:
        Character(const std::string &name);
        ~Character() { };

        void equip(AWeapon *weapon) { this->_weapon = weapon; };
        void attack(AEnemy *enemy);
        bool action(int cost);
        void recoverAP();

        int getAp() const { return (this->_ap); };
        std::string const &getName() const { return (this->_name); };
        AWeapon *getWeapon() const { return (this->_weapon); };
};

std::ostream &operator<<(std::ostream &os, Character const &perso);

#endif