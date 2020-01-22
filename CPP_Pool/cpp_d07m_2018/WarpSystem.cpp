/*
** EPITECH PROJECT, 2018
** WarpSystem.cpp
** File description:
** Exersice 2 - Get Moving!
*/

#include <iostream>
#include <fstream>
#include "Federation.hpp"
#include "WarpSystem.hpp"

WarpSystem::QuantumReactor::QuantumReactor()
{
    this->_stability = true;
}

WarpSystem::QuantumReactor::~QuantumReactor()
{

}

WarpSystem::Core::Core(QuantumReactor *_coreReactor)
{
    this->_coreReactor = _coreReactor;
}

WarpSystem::Core::~Core()
{

}

bool WarpSystem::QuantumReactor::isStable()
{
    return (this->_stability);
}

void WarpSystem::QuantumReactor::setStability(bool stability)
{
    this->_stability = stability;
}

WarpSystem::QuantumReactor *WarpSystem::Core::checkReactor()
{
    return (this->_coreReactor);
}