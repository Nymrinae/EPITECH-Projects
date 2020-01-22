/*
** EPITECH PROJECT, 2018
** Skat.cpp
** File description:
** Exersice 0 - Meeeeeeedic
*/

#include "Skat.hpp"

Skat::Skat(const std::string &name , unsigned int stimPaks)
{
    this->_name = name;
    this->_stimPaks = stimPaks;
}

void Skat::addStimPaks(unsigned int number)
{
    if (number == 0)
        std::cout << "Hey boya, did you forget something?" << std::endl;

    this->_stimPaks += number;
}

void Skat::useStimPaks()
{
    if (this->_stimPaks > 0) {
        this->_stimPaks--;
        std::cout << "Time to kick some ass and chew bubble gum." << std::endl;
    } else 
        std::cout << "Mediiiiiic" << std::endl;
}

void Skat::shareStimPaks(int number, int &stock)
{
    if (number < this->_stimPaks) {
        stock += number;
        this->_stimPaks -= number;
        std::cout << "Keep the change." << std::endl;
    } else
        std::cout << "Don't be greedy" << std::endl;
}

void Skat::status()
{
    std::cout << "Soldier " << this->_name << " reporting " << this->_stimPaks << " stimpaks remaining sir!" << std::endl;
}