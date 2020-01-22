/*
** EPITECH PROJECT, 2018
** Character.cpp
** File description:
** Exersice 1 - Family Matters
*/

#include "Character.hpp"

// ________________  BASE CHARACTER _____________ //

Character::Character(const std::string &name, int level)
{
    this->_name = name;
    this->_level = level;
    this->_pv = 100;
    this->_power = 100;
    this->_strength = 5;
    this->_stamina = 5;
    this->_spirit = 5;
    this->_agility = 5;
    this->_intelligence = 5;
    this->Range = CLOSE;

    std::cout << this->_name << " Created" << std::endl; 
}

int Character::CloseAttack()
{
    if (this->_power >= 10) {
        this->_power -= 10;
        std::cout << this->_name << " strikes with a wooden stick" << std::endl;
    } else {
        std::cout << this->_name << " out of power" << std::endl;
        return (0);
    }

    return (10 + this->_strength);
}

int Character::RangeAttack()
{
    if (this->_power >= 10) {
        this->_power -= 10;
        std::cout << this->_name << " tosses a stone" << std::endl;
    } else {
        std::cout << this->_name << " out of power" << std::endl;
        return (0);
    }

    return (5 + this->_strength);
}

void Character::Heal()
{
    this->_pv += 50;
    if (this->_pv > 100)
        this->_pv = 100;
    std::cout << this->_name << " takes a potion" << std::endl;
}

void Character::RestorePower()
{
    this->_power = 100;
    std::cout << this->_name << " eats" << std::endl;
}

void Character::TakeDamage(int damage)
{
    this->_pv -= damage;

    if (this->_pv <= 0)
        std::cout << this->_name << " out of combat" << std::endl;
    else
        std::cout << this->_name << " takes " << damage << " damage" << std::endl;
}