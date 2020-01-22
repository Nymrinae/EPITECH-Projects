/*
** EPITECH PROJECT, 2018
** Lime.cpp
** File description:
** Exersice 1 - Can I have some more ?
*/

#include "Lime.hpp"

Lime::Lime()
{
    this->_name = "lime";
    this->_vitamins = 2;
}

Lime::Lime(Lime const &l) : Lemon()
{
    this->_name = l.getName();
    this->_vitamins = l.getVitamins();
}

Lime& Lime::operator=(Lime const &Lime)
{
    this->_name = Lime.getName();
    this->_vitamins = Lime.getVitamins();

    return (*this);
}