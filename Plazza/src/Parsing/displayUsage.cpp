/*
** EPITECH PROJET, 2018
** filename
** File description:
** description?
*/

#include <iostream>

void displayUsage()
{
    std::cout << " ----------------------------------------- " << std::endl;
    std::cout << "USAGE" << std::endl;
    std::cout << "\t./plazza multiplier cooks time\n" << std::endl;
    std::cout << "DESCRIPTION" << std::endl;
    std::cout << "\t multiplier : multiplier for the cooking time"
        << std::endl;
    std::cout << "\t cooks : number of cooks per kitchen" << std::endl;
    std::cout << "\t time : time is the time in milliseconds, "
                    "used by the kitchen stock to replace ingredients\n"
        << std::endl;
    std::cout << "EXAMPLE" << std::endl;
    std::cout << "\t ./plazza 0.7 5 2000" << std::endl;
}