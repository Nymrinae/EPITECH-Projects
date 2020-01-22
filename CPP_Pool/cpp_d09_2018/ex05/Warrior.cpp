/*
** EPITECH PROJECT, 2018
** Warrior.hpp
** File description:
** Exercise 2 - Existentialism
*/

#include "Warrior.hpp"

Warrior::Warrior(const std::string &name, int level, bool is_warrior) : Character(name, level)
{
    std::string scream = " KKKKKKKKKKRRRRRRRRRRRRRREEEEEEEEOOOOOOORRRRGGGGGGG";
    this->_race = "Koala";
    this->_weaponName = "hammer";
    this->_strength = 12;
    this->_stamina = 12;
    this->_intelligence = 6;
    this->_agility = 7;

    if (is_warrior)
        std::cout << "I'm " << this->_name << scream << std::endl;
}

int Warrior::CloseAttack()
{
    if (this->_power >= 30) {
        this->_power -= 30;
        std::cout << this->_name << " strikes with his " << this->_weaponName << std::endl;
    } else {
        std::cout << this->_name << " out of power" << std::endl;
        return (0);
    }

    return (20 + this->_strength);
}

int Warrior::RangeAttack()
{
    if (this->_power >= 10) {
        this->_power -= 10;
        std::cout << this->_name << " intercepts" << std::endl;
        this->Range = CLOSE;
    } else
        std::cout << this->_name << " out of power" << std::endl;

    return (0);
}
