/*
** EPITECH PROJECT, 2019
** Plazza
** File description:
** main.c
*/

// #include "SCommand.hpp"
// #include "Plazza.hpp"
// #include "Cook.hpp"

#include "IPC.hpp"
#include "Plazza.hpp"
#include "Reception.hpp"

int main(int ac, char **av)
{
    ArrayOfCommands command;

    if (!areArgumentsValid(ac, av)) {
        displayUsage();
        return 84;
    }    
    Reception r(atof(av[1]), atoi(av[2]), atof(av[3]));
    r.open();
    return 0;
}

// int main(int ac, char **av)
// {
//     HandleCookT handleCook(3);
//     Cook cook(3);
//     for (int i = 0; i < 9; ++i)
//         cook.assignCook(handleCook);
// }
