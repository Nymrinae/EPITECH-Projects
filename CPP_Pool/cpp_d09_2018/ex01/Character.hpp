/*
** EPITECH PROJECT, 2018
** Character.hpp
** File description:
** Exercise 1 - Family Matters
*/

#ifndef _CHARACTER_H
#define _CHARACTER_H

#include <iostream>
#include <string>

class Character {
    protected:
        std::string _name;
        int _level;
        int _pv;
        int _power;
        int _strength;
        int _stamina;
        int _spirit;
        int _agility;
        int _intelligence;

    public:
        int Range;
        enum AttackRange {
            RANGE,
            CLOSE
        };

        Character(const std::string &name, int level);
        ~Character() { };
        const std::string &getName() const { return this->_name; };
        int getLvl() const          { return this->_level; };
        int getPv() const           { return this->_pv; };
        int getPower() const        { return this->_power; };
        int getStamina() const      { return this->_stamina; };
        int getSpirit() const       { return this->_spirit; };
        int getAgility() const      { return this->_agility; };
        int getIntelligence() const { return this->_intelligence; };
        int getRange() const        { return this->Range; };

        int CloseAttack();
        int RangeAttack();
        void Heal();
        void RestorePower();
        void TakeDamage(int damage);
};

#endif