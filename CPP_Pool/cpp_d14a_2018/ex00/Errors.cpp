/*
** EPITECH PROJECT, 2018
** Errors.cpp
** File description:
** Exersice 0 - Errors
*/

#include "Errors.hpp"

NasaError::NasaError(std::string const &message, std::string const &component = "Unknown")
: _message(message), _component(component)
{

}

MissionCriticalError::MissionCriticalError(std::string const &message, std::string const &component)
: NasaError(message, component)
{

}

LifeCriticalError::LifeCriticalError(std::string const &message, std::string const &component)
: NasaError(message, component)
{

}

UserError::UserError(std::string const &message, std::string const &component)
: NasaError(message, component)
{

}

CommunicationError::CommunicationError(std::string const &message)
: NasaError(message, "Communication Device")
{

}

const std::string &NasaError::getComponent() const 
{
    return (this->_component);
}

const char *NasaError::what() const throw()
{
    return (this->_message.c_str());
}
