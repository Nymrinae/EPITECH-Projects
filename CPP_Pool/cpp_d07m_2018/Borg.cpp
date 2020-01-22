/*
** EPITECH PROJECT, 2018
** Borg.cpp
** File description:
** Exersice 2 - Get Moving!
*/

#include "Borg.hpp"

// _____________________________________________   BORG::SHIP  ______________________________________________________ //

Borg::Ship::Ship()
{
    this->_side = 300;
    this->_maxWarp = 9;
    this->_home = Destination::UNICOMPLEX;
    this->_location = this->_home;

    std::cout << "We are the Borgs. Lower your shields and surrender yourselves unconditionally.\n";
    std::cout << "Your biological characteristics and technologies will be assimilated.\n";
    std::cout << "Resistance is futile.\n" << "\0";
}

Borg::Ship::~Ship()
{

}

void Borg::Ship::setupCore(WarpSystem::Core *core)
{
    _coreReactor = core;
}

void Borg::Ship::checkCore()
{
    std::string good = "Everything is in order.\n";
    std::string bad = "Critical failure imminent.\n";

    std::cout << ((_coreReactor->checkReactor()->isStable()) ? good : bad) << "\0";
}

bool Borg::Ship::move() {
    bool reactor = _coreReactor->checkReactor()->isStable();

    if (this->_location == this->_home || !reactor)
        return (false);
    this->_location = this->_home;

    return (true);
}

bool Borg::Ship::move(int warp)
{
    bool reactor = _coreReactor->checkReactor()->isStable();

    if(warp > this->_maxWarp || !reactor || this->_location == this->_home)
        return (false);
    this->_location = this->_home;

    return (true);
}

bool Borg::Ship::move(Destination d)
{
    bool reactor = _coreReactor->checkReactor()->isStable();
    
    if(reactor || this->_location == this->_home)
        return (false);

    this->_location = d;
    return (true);
}

bool Borg::Ship::move(int warp, Destination d)
{
    bool reactor = _coreReactor->checkReactor()->isStable();

    if(warp > this->_maxWarp || reactor || this->_location == this->_home)
        return (false);

    this->_location = d;
    return (true);
}