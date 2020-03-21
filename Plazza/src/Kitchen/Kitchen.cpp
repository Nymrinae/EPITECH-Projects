/*
** EPITECH PROJECT, 2019
** Plazza
** File description:
** main.c
*/

#include "Cook.hpp"
#include "Kitchen.hpp"

Kitchen::Kitchen(SCommand c, float m, int cooks, int s) :
_m(m),
_cooks(cooks),
_s(s),
_sCommand(c)
{
}

Kitchen::~Kitchen()
{

}

void Kitchen::giveCmd(const std::string &pizzaName)
{
    Cook cook(this->_cooks);
    HandleCookT handleCook(this->_cooks);

    handleCook._cookTime = this->_m;
    handleCook._refreshTime = this->_s;
    handleCook._pizzaName = pizzaName;
    cook.assignCook(handleCook);
    //exit(0);
}
