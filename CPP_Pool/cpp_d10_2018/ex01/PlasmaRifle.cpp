/*
** EPITECH PROJECT, 2018
** PlasmaRifle.cpp
** File description:
** Exercise 1 - Let them burn
*/

#include "PlasmaRifle.hpp"

PlasmaRifle::PlasmaRifle() : AWeapon("Plasma Rifle", 5, 21)
{

}

void PlasmaRifle::attack() const
{
    std::cout << "*piouuu piouuu piouuu *" << std::endl;
}