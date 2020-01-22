/*
** EPITECH PROJECT, 2018
** Peon.hpp
** File description:
** Exercise 0 - Ponymorphism
*/

#include "Peon.hpp"

Peon::Peon(const std::string &name) : Victim(name)
{
    this->_name = name;
    std::cout << "Zog zog." << std::endl;
}

Peon::~Peon()
{
    std::cout << "Bleuark..." << std::endl;
}

void Peon::getPolymorphed() const {
    std::cout << this->_name << " has been turned into a pink pony!" << std::endl;
}