/*
** EPITECH PROJECT, 2018
** Picture.cpp
** File description:
** Exersice 2 - Simple inheritance
*/

#ifndef _PICTURE_H
#define _PICTURE_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

class Picture {

    public:
        std::string _data;

        Picture();
        Picture(const std::string &file);
        ~Picture() { };

        bool getPictureFromFile(const std::string &file);
};

#endif

