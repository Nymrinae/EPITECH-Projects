/*
** EPITECH PROJECT, 2018
** PowerFist.cpp
** File description:
** Exercise 1 - Let them burn
*/

#include "PowerFist.hpp"

PowerFist::PowerFist() : AWeapon("Power Fist", 8, 50)
{

}

void PowerFist::attack() const
{
    std::cout << "* pachhh... SBAM! *" << std::endl;
}