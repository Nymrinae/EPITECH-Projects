/*
** EPITECH PROJECT, 2018
** Priest.hpp
** File description:
** Exercise 3 - Children
*/

#include "Priest.hpp"

Priest::Priest(const std::string &name, int level) : Character(name, level), Mage(name, level)
{
    this->_race = "Iopi";
    this->_strength = 4;
    this->_stamina = 4;
    this->_intelligence = 42;
    this->_spirit = 21;
    this->_agility = 2;

    std::cout << this->_name << " enters in the order" << std::endl;
}

int Priest::CloseAttack()
{
    this->Range = RANGE;
    if (this->_power >= 10) {
        this->_power -= 10;
        std::cout << this->_name << " uses a spirit explosion" << std::endl;
    } else
        std::cout << this->_name << " out of power" << std::endl;

    return (0);
}

void Priest::Heal()
{
    if(this->_power > 10) {
        this->_power -= 10;
        this->_pv += 50;

        if (this->_pv > 100)
            this->_pv = 100;
    }
    std::cout << this->_name << " casts a little heal spell" << std::endl;
}