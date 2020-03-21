/*
** EPITECH PROJECT, 2019
** Plazza
** File description:
** main.c
*/

#ifndef _INGREDIENT_H_
#define _INGREDIENT_H_

#include "Plazza.hpp"

enum eIngredient {
    DOE,
    TOMATO,
    GRUYERE,
    HAM,
    MUSHROOMS,
    STEAK,
    EGGPLANT,
    GOATCHEESE,
    CHIEFLOVE
};

class Ingredient {
    private:
        std::map<eIngredient, int> _ingredientSet;
        std::map<std::string, std::vector<eIngredient>> _typePizzas;

    public:
        Ingredient();
        ~Ingredient();

        void initMenu();
        void regenerate(int);
        void generateSet();
        bool isEnoughIngredients(std::string const &);
        std::map<eIngredient, int> getIngredientSet() { return this->_ingredientSet; };
};

#endif