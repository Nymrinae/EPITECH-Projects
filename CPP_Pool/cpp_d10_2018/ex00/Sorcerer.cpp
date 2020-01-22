/*
** EPITECH PROJECT, 2018
** Sorcerer.hpp
** File description:
** Exercise 0 - Ponymorphism
*/

#include "Sorcerer.hpp"

Sorcerer::Sorcerer(const std::string &name, const std::string &title)
{
    this->_name = name;
    this->_title = title;
    std::cout << this->_name << ", " << this->_title << ", is born!" << std::endl;
}

Sorcerer::~Sorcerer()
{
    std::cout << this->_name << ", " << this->_title << ", is dead. Consequences will never be the same!" << std::endl;
}

void Sorcerer::polymorph(Victim const &Victim) const {
    Victim.getPolymorphed();
}

std::ostream& operator<<(std::ostream &os, Sorcerer const &Sorcerer)
{
    os << "I am " << Sorcerer.getName() << ", " << Sorcerer.getTitle() << ", and I like ponies!" << std::endl;

    return (os);
}

