/*
** EPITECH PROJECT, 2019
** Plazza
** File description:
** 
*/

#ifndef _SCOMMAND_H
#define _SCOMMAND_H

#include "Plazza.hpp"
#include "Ingredient.hpp"

class SCommand {
    private:
        std::map<std::string, int> _typeMap;
        std::map<std::string, int> _sizeMap;
        std::pair<int, int> _pizzaEnumProperties;
        std::pair<std::string, std::string> _pizzaProperties;
        std::map<PizzaType, std::vector<eIngredient>> _typePizzas;

    public:
        SCommand(std::string, std::string);
        ~SCommand();
        void serialize(std::string, std::string);
        void unserialize();
        std::pair<std::string, std::string> getPizzaProperties() const { return this->_pizzaProperties; };
        std::pair<int, int> getCommandProperties() const { return this->_pizzaEnumProperties; };
};

#endif