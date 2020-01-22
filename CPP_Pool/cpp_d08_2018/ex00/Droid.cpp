/*
** EPITECH PROJECT, 2018
** .cpp
** File description:
** ???
*/

#include "Droid.hpp"

Droid::Droid(std::string id) : _id(id), _energy(50), _atk(25), _tough(15)
{
    this->_status = new std::string("Standing-by");
    speak("Activated");
}

Droid::Droid(Droid &droid) : _id(droid._id), _energy(droid._energy), _atk(droid._atk), _tough(droid._tough)
{
    this->_status = new std::string(droid._status ? *(droid._status) : "Standing by");
    speak("Activated, Memory Dumped");
}

Droid::~Droid()
{
    if (this->_status)
        delete (_status);
    speak("Destroyed");
}

Droid& Droid::operator=(Droid const &droid)
{
    this->_id = droid._id;
    this->_energy = droid._energy;
    if (this->_status)
        delete (this->_status);
    this->_status = new std::string(*(droid._status));

    return (*this);
}

bool Droid::operator==(const Droid &droid) const
{
    return (this->_id == droid._id && 
            this->_energy == droid._energy &&
            this->_atk == droid._atk &&
            this->_tough == droid._tough &&
            *(this->_status) == *(droid._status));
}

bool Droid::operator!=(const Droid &droid) const
{
    return (!(*this == droid));
}

Droid &Droid::operator<<(size_t &energy)
{
    int add;

    if (this->_energy < 100) {
        add = std::min(100 - this->_energy, energy);
        this->_energy += add;
        energy -= add;
    }
    return (*this);
}

void Droid::speak(std::string msg)
{
    std::cout << "Droid '" << this->_id << "' " << msg << std::endl;
}

std::ostream &operator<<(std::ostream &os, Droid const &droid)
{
    return os << "Droid '" << droid.getId() << "', " << *(droid.getStatus()) << ", " << droid.getEnergy();
}