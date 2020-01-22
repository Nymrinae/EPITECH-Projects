/*
** EPITECH PROJECT, 2018
** AWeapon.cpp
** File description:
** Exercise 1 - Let them burn
*/

#ifndef _POWERFIST_H
#define _POWERFIST_H

#include <iostream>
#include <string>

#include "AWeapon.cpp"

class PowerFist : public AWeapon {
    protected:

    public:
        PowerFist();
        virtual ~PowerFist() { };
        virtual void attack() const;
};


#endif