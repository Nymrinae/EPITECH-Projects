/*
** EPITECH PROJECT, 2018
** Parts.cpp
** File description:
** Exersice 1 - Koala Bot
*/

#include "Parts.hpp"

// _______________________ HEAD _______________________ //

Head::Head(std::string serial, bool isFunctionnal)
{
    this->_serial = serial;
    this->_isWorking = isFunctionnal;
}

Head::~Head(){}

std::string Head::serial()
{
    return (this->_serial);
}

bool Head::isFunctionnal()
{
    return (this->_isWorking);
}

void Head::informations()
{
    std::cout << "\t[Parts] Head " << this->_serial << " status : ";
    std::cout << (this->_isWorking ? "OK\n" : "KO\n") << "\0";
}

// _______________________ ARMS _______________________ //

Arms::Arms(std::string serial, bool isFunctionnal)
{
    this->_serial = serial;
    this->_isWorking = isFunctionnal;
}

Arms::~Arms() {}

std::string Arms::serial()
{
    return (this->_serial);
}

bool Arms::isFunctionnal()
{
    return (this->_isWorking);
}

void Arms::informations()
{
    std::cout << "\t[Parts] Arms " << this->_serial << " status : ";
    std::cout << (this->_isWorking ? "OK\n" : "KO\n") << "\0";
}

// _______________________ LEGS _______________________ //

Legs::Legs(std::string serial, bool isFunctionnal)
{
    this->_serial = serial;
    this->_isWorking = isFunctionnal;
}

Legs::~Legs() {}

std::string Legs::serial()
{
    return (this->_serial);
}

bool Legs::isFunctionnal()
{
    return (this->_isWorking);
}

void Legs::informations()
{
    std::cout << "\t[Parts] Legs " << this->_serial << " status : ";
    std::cout << (this->_isWorking ? "OK\n" : "KO\n") << "\0";
}