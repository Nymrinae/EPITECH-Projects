/*
** EPITECH PROJECT, 2019
** Plazza
** File description:
** CookUtility.hpp
*/

#pragma once

#include <vector>
#include "Busy.hpp"
#include "Roll.hpp"
#include "Ingredient.hpp"

typedef struct HandleCookS {
    explicit HandleCookS(const std::size_t &cookNb);
    Busy status;
    Roll roll;
    Ingredient ingredient;
    
    std::vector<bool> _isRoll;
    std::size_t _itCook;
    bool _taskOk;
    
    std::string _pizzaName;
    int _cookTime;
    int _refreshTime;
} HandleCookT;

extern void *workInProgress(void *obj);
extern void *manageCook(void *obj);
