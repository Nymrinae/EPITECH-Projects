/*
** EPITECH PROJECT, 2018
** Paladin.hpp
** File description:
** Exercise 3 - Children
*/

#include "Paladin.hpp"

Paladin::Paladin(const std::string &name, int level) : Character(name, level), Warrior(name, level, 1), Priest(name, level)
{
    this->_race = "Human";
    this->_strength = 9;
    this->_stamina = 10;
    this->_intelligence = 10;
    this->_spirit = 10;
    this->_agility = 2;

    std::cout << "the light falls on " << this->_name << std::endl;
}

int Paladin::Intercept()
{
    return (Warrior::RangeAttack());
}

