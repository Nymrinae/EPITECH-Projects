/*
** EPITECH PROJECT, 2018
** AEnemy.cpp
** File description:
** Exercise 1 - Let them burn
*/

#include "AEnemy.hpp"

AEnemy::AEnemy(int hp, const std::string &type)
{
    this->_hp = hp;
    this->_type = type;
}

void AEnemy::takeDamage(int damage)
{
    if (damage > 0)
        this->_hp -= damage;
    if (this->_hp < 0)
        delete (this);
}