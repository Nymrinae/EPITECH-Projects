/*
** EPITECH PROJECT, 2018
** Toy.cpp
** File description:
** Exersice 2 - Simple inheritance
*/

#include "Toy.hpp"

Toy::Toy() {
    this->_type = BASIC_TOY;
    this->_name = "toy";
}

Toy::Toy(Toy const &Toy)
{
    this->_name = Toy._name;
    this->_type = Toy._type;
    this->_picture = Toy._picture;
}

Toy::Toy(ToyType type, const std::string &name, const std::string &filename)
{
    this->_type = type;
    this->_name = name;
    this->_picture = filename;
}

int Toy::getType() const
{
    return (this->_type);
}

const std::string &Toy::getName() const
{
    return (this->_name);
}

const std::string &Toy::getAscii() const
{
    return (this->_picture._data);
}

void Toy::setName(const std::string &name)
{
    this->_name = name;
}

bool Toy::setAscii(const std::string &name)
{
    return ((this->_picture).getPictureFromFile(name));
}

Toy Toy::operator=(Toy const &Toy)
{
   this->_name = Toy._name;
   this->_type = Toy._type;
   this->_picture = Toy._picture;

   return (*this);
}