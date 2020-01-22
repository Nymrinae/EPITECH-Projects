/*
** EPITECH PROJECT, 2018
** AWeapon.cpp
** File description:
** Exercise 1 - Let them burn
*/

#ifndef _PLASMARIFLE_H
#define _PLASMARIFLE_H

#include <iostream>
#include <string>

#include "AWeapon.cpp"

class PlasmaRifle : public AWeapon {
    protected:

    public:
        PlasmaRifle();
        virtual      ~PlasmaRifle() { };
        virtual void attack() const;
};


#endif