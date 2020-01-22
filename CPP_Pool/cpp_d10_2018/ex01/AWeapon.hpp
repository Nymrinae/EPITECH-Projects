/*
** EPITECH PROJECT, 2018
** AWeapon.cpp
** File description:
** Exercise 1 - Let them burn
*/

#ifndef _AWEAPON_H
#define _AWEAPON_H

#include <iostream>
#include <string>

class AWeapon {
    private:
        std::string _name;
        int _apcost;
        int _damage;

    public:
        AWeapon(const std::string &name, int apcost, int damage);
        virtual ~AWeapon() { };
        std::string const &getName() const { return (this->_name); };
        int getAPCost()              const { return (this->_apcost); };
        int getDamage()              const { return (this->_damage); };
        virtual void attack()        const = 0;
};

#endif