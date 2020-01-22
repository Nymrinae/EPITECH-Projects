/*
** EPITECH PROJECT, 2018
** Sorcerer.hpp
** File description:
** Exercise 0 - Ponymorphism
*/

#ifndef _SORCERER_H
#define _SORCERER_H

#include <iostream>
#include <string>

#include "Victim.hpp"
#include "Peon.hpp" 

class Sorcerer {
    protected:
        std::string _name;
        std::string _title;
    public:
        Sorcerer(const std::string &name, const std::string &title);
        ~Sorcerer();

        const std::string &getName()            const { return this->_name; };
        const std::string &getTitle()           const { return this->_title; };
        void polymorph(const Victim &Victim)    const;
};

std::ostream& operator<<(std::ostream &os, Sorcerer const &Sorcerer);

#endif