/*
** EPITECH PROJECT, 2018
** Toy.cpp
** File description:
** Exersice 2 - Simple inheritance
*/

#include "Woody.hpp"

Woody::Woody(std::string const &name) 
: Toy (WOODY, name, "")
{

}

Woody::Woody(std::string const &name, std::string const &filename)
: Toy(WOODY, name, filename)
{

}

void Woody::speak(const std::string msg)
{
    std::cout << "WOODY: " << this->_name << " \"" << msg << "\"" << std::endl;     
}