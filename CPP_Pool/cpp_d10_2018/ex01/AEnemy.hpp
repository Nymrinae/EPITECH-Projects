/*
** EPITECH PROJECT, 2018
** AEnemy.cpp
** File description:
** Exercise 1 - Let them burn
*/

#ifndef _AENEMY_H
#define _AENEMY_H

#include <iostream>
#include <string>

class AEnemy {
    private:
        int _hp;
        std::string _type;

    public:
        AEnemy(int hp, const std::string &type);
        virtual ~AEnemy() { };

        virtual void takeDamage(int damage);
        std::string virtual getType() const { return (this->_type); };
        int getHP() const { return (this->_hp); };
};

#endif