/*
** EPITECH PROJECT, 2019
** Plazza
** File description:
** main.c
*/

#ifndef _KITCHEN_H_
#define _KITCHEN_H_

#include "Plazza.hpp"
#include "SCommand.hpp"

class Kitchen {
    private:
        float   _m;
        int     _cooks;
        int     _s;
        SCommand _sCommand;

    public:
        Kitchen(SCommand, float, int, int);
        ~Kitchen();

        void giveCmd(const std::string &pizzaName);
};
#endif
