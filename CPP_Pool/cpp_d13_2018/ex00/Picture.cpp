/*
** EPITECH PROJECT, 2018
** Picture.cpp
** File description:
** Exersice 0 : Encapsulation
*/

#include "Picture.hpp"

Picture::Picture()
{
    this->_data = "";
}

Picture::Picture(const std::string &file)
{
    getPictureFromFile(file);
}

bool Picture::getPictureFromFile(const std::string &file)
{
    std::ifstream filename(file.data());

    if (filename.is_open()) {
        std::stringstream buffer;
        buffer << filename.rdbuf();
        this->_data = buffer.str();
        filename.close();
        return (true);
    }
    this->_data = "ERROR";
    return (false);
}