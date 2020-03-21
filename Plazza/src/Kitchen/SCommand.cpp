/*
** EPITECH PROJECT, 2019
** Plazza
** File description:
** main.c
*/

#include "SCommand.hpp"

SCommand::SCommand(std::string t, std::string s)
{
    this->_pizzaProperties.first = t;
    this->_pizzaProperties.second = s;
    serialize(t, s);
}

SCommand::~SCommand()
{

}

void SCommand::serialize(std::string t, std::string s)
{
    int typePos;
    int sizePos;
    std::map<std::string, int> typeMap;
    std::map<std::string, int> sizeMap;
    std::pair<int, int> SCommandEnumProperties;

    std::transform(t.begin(), t.begin() + 1, t.begin(), ::toupper);
    std::transform(s.begin(), s.end(), s.begin(), ::toupper);

    typeMap.insert({ "Regina", Regina });
    typeMap.insert({ "Margarita", Margarita });
    typeMap.insert({ "Americana", Americana });
    typeMap.insert({ "Fantasia", Fantasia });

    sizeMap.insert({ "S", S });
    sizeMap.insert({ "M", M });
    sizeMap.insert({ "L", L });
    sizeMap.insert({ "XL", XL });
    sizeMap.insert({ "XXL", XXL });

    typePos = typeMap.find(t)->second;
    sizePos = sizeMap.find(s)->second;

    SCommandEnumProperties.first = typePos;
    SCommandEnumProperties.second = sizePos;

    this->_typeMap = typeMap;
    this->_sizeMap = sizeMap;
    this->_pizzaEnumProperties = SCommandEnumProperties;
}

void SCommand::unserialize()
{
    std::string itType;
    std::string itSize;
    std::map<std::string, int>::iterator it;
    int type = this->_pizzaEnumProperties.first;
    int size = this->_pizzaEnumProperties.second;

    for (it = this->_typeMap.begin(); it != this->_typeMap.end(); ++it)
        if (it->second == type) {
            itType = it->first;
            std::transform(itType.begin(), itType.end(), itType.begin(), ::tolower);
            this->_pizzaProperties.first = itType;
        }
    
    for (it = this->_sizeMap.begin(); it != this->_sizeMap.end(); ++it)
        if (it->second == size) {
            itSize = it->first;
            std::transform(itSize.begin(), itSize.end(), itSize.begin(), ::tolower);
            this->_pizzaProperties.second = itSize;
        }
}


