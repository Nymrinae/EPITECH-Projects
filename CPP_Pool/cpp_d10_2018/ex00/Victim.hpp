/*
** EPITECH PROJECT, 2018
** Victim.hpp
** File description:
** Exercise 0 - Ponymorphism
*/

#ifndef _VICTIM_H
#define _VICTIM_H

#include <iostream>
#include <string>

class Victim {
    protected:
        std::string _name;
    public:
        Victim(const std::string &name);
        ~Victim();

        const std::string &getName() const { return this->_name; };
        virtual void getPolymorphed() const;
};

std::ostream& operator<<(std::ostream &os, Victim const &Victim);

#endif