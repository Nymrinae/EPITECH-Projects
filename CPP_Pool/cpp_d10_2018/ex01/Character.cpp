/*
** EPITECH PROJECT, 2018
** Character.cpp
** File description:
** Exercise 1 - Let them burn
*/

#include "Character.hpp"

Character::Character(const std::string &name)
{
    this->_name = name;
    this->_ap = 40;
}

void Character::recoverAP()
{
    this->_ap = 40;
    if (this->_ap > 40)
        this->_ap = 40;
}

bool Character::action(int cost)
{
    if (this->_ap >= cost) {
        this->_ap -= cost;
        return  (true);
    }
    return (false);
}

void Character::attack(AEnemy *enemy)
{
    if (this->_weapon && enemy) {
        if(action(this->_weapon->getApCost())) {
            std::cout << this->_name << " attacks " << enemy->getType();
            std::cout << " with a " << this->_weapon->getName() << std::endl;
            this->_weapon->attack();
            enemy->takeDamage(this->_weapon->getDamage());
            if (enemy->getHP() <= 0)
                delete enemy;
        }
    }
}

std::ostream &operator<<(std::ostream &os, Character const &perso)
{
    if(perso.getWeapon())
        os << perso.getName() << " has " << perso.getAp() << " AP and wields a " << perso.getWeapon()->getName() << std::endl;
    else
        os << perso.getName() << " has " << perso.getAp() << " AP and is unarmed" << std::endl;
    
    return (os);
}