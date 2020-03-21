/*
** EPITECH PROJET, 2018
** filename
** File description:
** description?
*/

#include <iostream>

bool areArgumentsValid(int argc, char const * const argv[])
{
    if (argc != 4) {
        std::cerr << "[ERROR " << argv[0] << "] Expected 3 arguments, given "
            << argc - 1 << std::endl;
        return false;
    }
    try {
        if (std::stof(argv[1]) <= 0.f || std::stof(argv[2]) <= 0.f ||
            std::stof(argv[3]) < 0.f) {
            return false;
        }
    } catch (std::invalid_argument &e) {
        return false;
    }
    return true;
}
