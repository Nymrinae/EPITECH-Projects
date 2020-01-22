/*
** EPITECH PROJECT, 2018
** Cesar.cpp
** File description:
** Exersice 2 - Ave
*/

#include "Cesar.hpp"

Cesar::Cesar()
{
    reset();
}

void Cesar::reset()
{
    this->_nb = 3;
}

void Cesar::encryptChar(char c)
{
    int start;

    if (isalpha(c)) {
        start = ((c > 96) ? 97 : 65);
		c = (c - start + this->_nb) % 26 + start;
    }
	this->_nb = (this->_nb + 1) % 26;
    std::cout << c;
}

void Cesar::decryptChar(char c)
{
    int start;

    if (isalpha(c)) {
        start = ((c > 96) ? 122 : 90);
		c = (c - start - this->_nb) % 26 + start;
    }
	this->_nb = (this->_nb + 1) % 26;
    std::cout << c;
}