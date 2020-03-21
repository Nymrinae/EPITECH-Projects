/*
** EPITECH PROJECT, 2019
** Plazza
** File description:
** CookUtility.cpp
*/

#include <iostream>
#include <thread>
#include "CookUtility.hpp"

void *workInProgress(void *obj)
{
    HandleCookT *hCook(static_cast<HandleCookT *>(obj));

    hCook->status.doNotDisturb();
    while (!hCook->_isRoll[hCook->_itCook])
        hCook->roll.waitingForTheRoll(hCook->status.getLock());
    if (hCook->_pizzaName == "margarita") {
        hCook->ingredient.isEnoughIngredients(hCook->_pizzaName);
        //hCook->ingredient.regenerate(hCook->_refreshTime);
        std::this_thread::sleep_for(std::chrono::seconds(1 * hCook->_cookTime));
    }
    if (hCook->_pizzaName == "regina") {
        hCook->ingredient.isEnoughIngredients(hCook->_pizzaName);
        //hCook->ingredient.regenerate(hCook->_refreshTime);
        std::this_thread::sleep_for(std::chrono::seconds(2 * hCook->_cookTime));
    }
    if (hCook->_pizzaName == "americana") {
        hCook->ingredient.isEnoughIngredients(hCook->_pizzaName);
        //hCook->ingredient.regenerate(hCook->_refreshTime);
        std::this_thread::sleep_for(std::chrono::seconds(2 * hCook->_cookTime));
    }
    if (hCook->_pizzaName == "fantasia") {
        hCook->ingredient.isEnoughIngredients(hCook->_pizzaName);
        //hCook->ingredient.regenerate(hCook->_refreshTime);
        std::this_thread::sleep_for(std::chrono::seconds(4 * hCook->_cookTime));
    }
    hCook->_taskOk = true;
    std::cout << "Your " << hCook->_pizzaName << " is ready !" << std::endl;
    //hCook->_pizzaName = "";
    hCook->status.avaible();
    hCook->_pizzaName = "";
    pthread_exit(NULL);
    return NULL;
}

void *manageCook(void *obj)
{
    HandleCookT *hCook(static_cast<HandleCookT *>(obj));

    //std::cout << "Assign new cook" << std::endl;
    hCook->status.doNotDisturb();
    hCook->_isRoll[hCook->_itCook] = true;
    hCook->roll.assignCook();
    hCook->status.avaible();
    pthread_exit(NULL);
    return NULL;
}

HandleCookS::HandleCookS(const std::size_t &cookNb) :
    status(), roll(), ingredient(),_isRoll(cookNb, false),
    _itCook(0), _taskOk(false), _pizzaName(""), _cookTime(0), _refreshTime(0)
{}
