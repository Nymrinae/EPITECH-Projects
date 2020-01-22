/*
** EPITECH PROJECT, 2018
** Banana.cpp
** File description:
** Exersice 0 - Fruits
*/

#include "Banana.hpp"

Banana::Banana()
: Fruit(5, "banana")
{

}

Banana::Banana(Banana const &Banana)
: Fruit (Banana.getVitamins(), Banana.getName())
{
    
}

Banana& Banana::operator=(Banana const &Banana)
{
    this->_name = Banana.getName();
    this->_vitamins = Banana.getVitamins();

    return (*this);
}

std::string Banana::getName() const
{
    return (this->_name);
}

int Banana::getVitamins() const
{
    return (this->_vitamins);
}
