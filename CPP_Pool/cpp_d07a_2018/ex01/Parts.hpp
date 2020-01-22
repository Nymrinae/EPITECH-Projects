/*
** EPITECH PROJECT, 2018
** Parts.cpp
** File description:
** Exersice 1 - Koala Bot
*/

#ifndef _PARTS_H
#define _PARTS_H

#include <string>
#include <iostream>

class Head {

    private:
        std::string _serial;
        bool _isWorking;

    public:
        Head(std::string serial = "H-01", bool isWorking = true);
        ~Head();
        bool        isFunctionnal();
        std::string serial();
        void        informations();
};

class Arms {

    private:
        std::string _serial;
        bool _isWorking;

    public:
        Arms(std::string serial = "A-01", bool isWorking = true);
        ~Arms();
        bool        isFunctionnal();
        std::string serial();
        void        informations();
};

class Legs {

    private:
        std::string _serial;
        bool _isWorking;

    public:
        Legs(std::string serial = "L-01", bool isWorking = true);
        ~Legs();
        bool        isFunctionnal();
        std::string serial();
        void        informations();
};

#endif
