/*
** EPITECH PROJECT, 2018
** Skat.cpp
** File description:
** Exersice 0 - Meeeeeeedic
*/

#ifndef _SKAT_H
#define _SKAT_H

#include <string>
#include <algorithm>
#include <iostream>
#include <fstream>

class Skat {
    private:
        std::string     _name;
        int             _stimPaks;

    public:
        Skat(const std::string &name = "bob", unsigned int stimPaks = 15);
        ~Skat() { };

        int &stimPaks()             { return (this->_stimPaks); };
        const std::string &name()   { return (this->_name); };

        void shareStimPaks(int number, int &stock);
        void addStimPaks(unsigned int number);
        void useStimPaks();
        void status();
};

#endif