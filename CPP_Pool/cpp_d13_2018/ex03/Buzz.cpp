/*
** EPITECH PROJECT, 2018
** Buzz.cpp
** File description:
** Exersice 2 - Simple inheritance
*/

#include "Buzz.hpp"

Buzz::Buzz(std::string const &name) 
: Toy (BUZZ, name, "")
{

}

Buzz::Buzz(std::string const &name, std::string const &filename)
: Toy(BUZZ, name, filename)
{

}

void Buzz::speak(const std::string msg)
{
    std::cout << "BUZZ: " << this->_name << " \"" << msg << "\"" << std::endl;
}