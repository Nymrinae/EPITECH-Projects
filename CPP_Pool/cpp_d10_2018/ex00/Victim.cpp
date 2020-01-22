/*
** EPITECH PROJECT, 2018
** Victim.hpp
** File description:
** Exercise 0 - Ponymorphism
*/

#include "Victim.hpp"

Victim::Victim(const std::string &name)
{
    this->_name = name;
    std::cout << "Some random victim called " << this->_name << " just popped!" << std::endl;
}

Victim::~Victim()
{
    std::cout << "Victim " << this->_name << " just died for no apparent reason!" << std::endl;
}

void Victim::getPolymorphed() const {
    std::cout << this->_name << " has been turned into a cute little sheep!" << std::endl;
}

std::ostream& operator<<(std::ostream &os, Victim const &Victim)
{
    os << "I'm " << Victim.getName() << " and i like otters!" << std::endl;

    return (os);
}
