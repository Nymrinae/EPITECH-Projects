/*
** EPITECH PROJECT, 2018
** Mage.hpp
** File description:
** Exercise 3 - Children
*/

#include "Mage.hpp"

Mage::Mage(const std::string &name, int level) : Character(name, level)
{
    this->_race = "Gnome";
    this->_strength = 6;
    this->_stamina = 6;
    this->_intelligence = 12;
    this->_spirit = 11;
    this->_agility = 7;

    std::cout << this->_name << " teleported" << std::endl;
}

int Mage::CloseAttack()
{
    this->Range = RANGE;
    if (this->_power >= 10) {
        this->_power -= 10;
        std::cout << this->_name << " blinks" << std::endl;
    } else
        std::cout << this->_name << " out of power" << std::endl;

    return (0);
}

int Mage::RangeAttack()
{
    if (this->_power >= 25) {
        this->_power -= 25;
        std::cout << this->_name << " launches a fire ball" << std::endl;
    } else
        std::cout << this->_name << " out of power" << std::endl;

    return (20 + this->_spirit);
}

void Mage::RestorePower()
{
    this->_power = 50 + this->_intelligence;
    if (this->_power > 100)
        this->_power = 100;
    std::cout << this->_name << " takes a mana potion" << std::endl;
}