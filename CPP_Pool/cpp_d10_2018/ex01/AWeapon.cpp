/*
** EPITECH PROJECT, 2018
** AWeapon.cpp
** File description:
** Exercise 1 - Let them burn
*/

#include "AWeapon.hpp"

AWeapon::AWeapon(const std::string &name, int apcost, int damage)
{
    this->_name = name;
    this->_apcost = apcost;
    this->_damage = damage;
}