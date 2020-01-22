/*
** EPITECH PROJECT, 2018
** Federation.cpp
** File description:
** Exersice 2 - Get Moving!
*/

#include <iostream>
#include <fstream>
#include "Federation.hpp"

// _____________________________________________   FEDERATION::STARFLEET::SHIP ______________________________________________________ //

Federation::Starfleet::Ship::Ship(int length, int width, std::string name, short maxWarp)
{
    this->_length = length;
    this->_width = width;
    this->_name = name;
    this->_maxWarp = maxWarp;
    this->_home = Destination::EARTH;
    this->_location = this->_home;

    std::cout << "The ship USS " << this->_name << " has been finished.\n";
    std::cout << "It is " << this->_length << " m in length and " << this->_width << " m in width.\n";
    std::cout << "It can go to Warp " << this->_maxWarp << "!\n" << "\0";
}

Federation::Starfleet::Ship::~Ship()
{
    this->_length = 0;
    this->_width = 0;
    this->_name.clear();
    this->_maxWarp = 0;
}

void Federation::Starfleet::Ship::setupCore(WarpSystem::Core* core)
{
    _coreReactor = core;
    std::cout << "USS " << this->_name << ": The core is set.\n" << "\0";
}

void Federation::Starfleet::Ship::checkCore()
{
    if (_coreReactor->checkReactor()->isStable())
        std::cout << "USS " << this->_name << ": The core is stable at the time.\n" << "\0";
    else
        std::cout << "USS " << this->_name << ": The core is unstable at the time.\n" << "\0";
}

bool Federation::Starfleet::Ship::move() {
    bool reactor = _coreReactor->checkReactor()->isStable();

    if (this->_location == this->_home || !reactor)
        return (false);
    this->_location = this->_home;

    return (true);
}

bool Federation::Starfleet::Ship::move(int warp)
{
    bool reactor = _coreReactor->checkReactor()->isStable();

    if(warp > this->_maxWarp || !reactor || this->_location == this->_home)
        return (false);
    this->_location = this->_home;

    return (true);
}

bool Federation::Starfleet::Ship::move(Destination d)
{
    bool reactor = _coreReactor->checkReactor()->isStable();
    
    if(reactor || this->_location == this->_home)
        return (false);

    this->_location = d;
    return (true);
}

bool Federation::Starfleet::Ship::move(int warp, Destination d)
{
    bool reactor = _coreReactor->checkReactor()->isStable();

    if(warp > this->_maxWarp || reactor || this->_location == this->_home)
        return (false);

    this->_location = d;
    return (true);
}

// _____________________________________________ FEDERATION::STARFLEET::CAPTAIN ______________________________________________________ //

Federation::Starfleet::Captain::Captain(std::string name)
{
    this->_name = name;
}

Federation::Starfleet::Captain::~Captain()
{

}

std::string Federation::Starfleet::Captain::getName()
{
    return(this->_name);
}

int Federation::Starfleet::Captain::getAge()
{
    return (this->_age);
}

void Federation::Starfleet::Captain::setAge(int age)
{
    this->_age = age;
}

void Federation::Starfleet::Ship::promote(Federation::Starfleet::Captain *captain)
{
    std::cout << captain->getName() << ": I'm glad to be the captain of the USS " << this->_name << ".\n\0";
}

// _____________________________________________   FEDERATION::STARFLEET::ENSIGN ______________________________________________________ //

Federation::Starfleet::Ensign::Ensign(std::string name)
{
    this->_name = name;
    std::cout << "Ensign " << this->_name << ", awaiting orders.\n" << "\0";
}

Federation::Starfleet::Ensign::~Ensign()
{

}

// _____________________________________________   FEDERATION::SHIP ______________________________________________________ //

Federation::Ship::Ship(int length, int width, std::string name)
{
    this->_length = length;
    this->_width = width;
    this->_name = name;
    this->_maxWarp = 1;
    this->_home = Destination::VULCAN;
    this->_location = this->_home;

    std::cout << "The independant ship " << this->_name << " just finished its construction.\n";
    std::cout << "It is " << this->_length << " m in length and " << this->_width << " m in width.\n";
}

Federation::Ship::~Ship()
{

}

void Federation::Ship::setupCore(WarpSystem::Core* core)
{
    _coreReactor = core;
    std::cout << this->_name << ": The core is set.\n" << "\0";    
}

void Federation::Ship::checkCore()
{
    if (_coreReactor->checkReactor()->isStable())
        std::cout << this->_name << ": The core is stable at the time.\n" << "\0";
    else
        std::cout << this->_name << ": The core is unstable at the time.\n" << "\0";
}

bool Federation::Ship::move() {
    bool reactor = _coreReactor->checkReactor()->isStable();

    if (this->_location == this->_home || !reactor)
        return (false);
    this->_location = this->_home;

    return (true);
}

bool Federation::Ship::move(int warp)
{
    bool reactor = _coreReactor->checkReactor()->isStable();

    if(warp > this->_maxWarp || !reactor || this->_location == this->_home)
        return (false);
    this->_location = this->_home;

    return (true);
}

bool Federation::Ship::move(Destination d)
{
    bool reactor = _coreReactor->checkReactor()->isStable();
    
    if(reactor || this->_location == this->_home)
        return (false);

    this->_location = d;
    return (true);
}

bool Federation::Ship::move(int warp, Destination d)
{
    bool reactor = _coreReactor->checkReactor()->isStable();

    if(warp > this->_maxWarp || reactor || this->_location == this->_home)
        return (false);

    this->_location = d;
    return (true);
}