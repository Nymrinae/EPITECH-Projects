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

bool Toy::speak(const std::string msg)
{
    std::cout << this->_name << " \"" << msg << "\" " << std::endl;

    return (true);
}

bool Toy::speak_es(std::string const msg) {

    (void)msg;
    this->err.type = Error::SPEAK;
    
    return (false);
}

Toy::Error::Error()
{
    this->type = UNKNOWN;
}

void Toy::Error::setType(ErrorType type)
{
    this->type = type;
}

bool Toy::setAscii(const std::string &name)
{
    bool file = (this->_picture).getPictureFromFile(name);
    
    if (!file)
        this->err.type = Error::PICTURE;

    return (file);
}

std::string Toy::Error::what() const 
{
    if (type == PICTURE)
        return ("bad new illustration");
    else if (type == SPEAK)
        return ("wrong mode");
    else
        return ("");
}

std::string Toy::Error::where() const 
{
    if (type == PICTURE)
        return ("setAscii");
    else if (type == SPEAK)
        return ("speak_es");
    else
        return ("");
}

const Toy::Error &Toy::getLastError() const {
	return (err);
}

Toy& Toy::operator=(Toy const &Toy)
{
   this->_name = Toy._name;
   this->_type = Toy._type;
   this->_picture = Toy._picture;

   return (*this);
}

Toy& Toy::operator<<(std::string const &str)
{
    _picture._data = str;

    return (*this);
}

std::ostream& operator<<(std::ostream &os, Toy const &Toy)
{
    os << Toy.getName() << std::endl << Toy.getAscii() << std::endl;

    return (os);
}