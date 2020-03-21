/*
** EPITECH PROJECT, 2019
** Plazza
** File description:
** main.c
*/

#include "Ingredient.hpp"

Ingredient::Ingredient()
{
    initMenu();
    generateSet();
}

Ingredient::~Ingredient()
{

}

void Ingredient::initMenu()
{
    std::map<std::string, std::vector<eIngredient>> typePizzas;
    std::vector<eIngredient> margarita = { DOE, TOMATO, GRUYERE };
    std::vector<eIngredient> regina = { DOE, TOMATO, GRUYERE, HAM, MUSHROOMS };
    std::vector<eIngredient> americana = { DOE, TOMATO, GRUYERE, STEAK };
    std::vector<eIngredient> fantasia = { DOE, TOMATO, EGGPLANT, GOATCHEESE, CHIEFLOVE };

    typePizzas.insert({ "margarita", margarita });
    typePizzas.insert({ "regina", regina });
    typePizzas.insert({ "americana", americana });
    typePizzas.insert({ "fantasia", fantasia });

    this->_typePizzas = typePizzas;
}

void Ingredient::generateSet()
{
    std::map<eIngredient, int> iSet;

    iSet.insert({ DOE, 5 });
    iSet.insert({ TOMATO, 5 });
    iSet.insert({ GRUYERE, 5 });
    iSet.insert({ HAM, 5 });
    iSet.insert({ MUSHROOMS, 5 });
    iSet.insert({ STEAK, 5 });
    iSet.insert({ EGGPLANT, 5 });
    iSet.insert({ GOATCHEESE, 5 });
    iSet.insert({ CHIEFLOVE, 5 });

    this->_ingredientSet = iSet;
}

void Ingredient::regenerate(int refreshTime)
{
    std::map<eIngredient, int>::iterator it;
    auto start = std::chrono::system_clock::now();
    auto end = std::chrono::system_clock::now();

    std::chrono::duration<double> elapsed_s = end - start;

    while (elapsed_s.count() <= refreshTime/1000) {
        end = std::chrono::system_clock::now();
        elapsed_s = end - start;
    }

    for (it = this->_ingredientSet.begin(); it != this->_ingredientSet.end(); ++it)
        it->second++;
}

bool Ingredient::isEnoughIngredients(std::string const &Pizza)
{
    eIngredient currentIg;
    std::vector<eIngredient> neededIg;

    neededIg = this->_typePizzas.find(Pizza)->second;

    for (auto i : neededIg) {
        currentIg = neededIg[i];
        if (this->_ingredientSet[currentIg] > 0)
            this->_ingredientSet[currentIg]--;
        else {
            std::cerr << "Not enough ingredients to make this Pizza" << std::endl;
            exit(84);
        }
    }
    return true;
}
