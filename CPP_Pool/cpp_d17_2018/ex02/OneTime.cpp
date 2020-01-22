/*
** EPITECH PROJECT, 2018
** OneTime.cpp
** File description:
** Exersice 2 - Ave
*/

#include "OneTime.hpp"

OneTime::OneTime(const std::string &key)
{
    this->_key = key;
    this->_i = 0;
}

void OneTime::encryptChar(char c)
{
    int base, key;

    if(isalpha(c)) {
        base = (c > 96) ? 97 : 65;
        key = (this->_key[this->_i] > 96) ? 97 : 65;
        c = (c - base + (this->_key[this->_i] - key)) % 26 + base;
    }
    std::cout << c;
    this->_i = (this->_i + 1) % this->_key.size();
}

void OneTime::decryptChar(char c)
{
    int base, key;

    if(isalpha(c)) {
        base = (c > 96) ? 122 : 90;
        key = (this->_key[this->_i] > 96) ? 97 : 65;
        c = (c - base - (this->_key[this->_i] - key)) % 26 + base;
    }
    std::cout << c;
    this->_i = (this->_i + 1) % this->_key.size();
}

void OneTime::reset() 
{
    this->_i = 0;
}