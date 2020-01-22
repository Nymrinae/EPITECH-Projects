/*
** EPITECH PROJECT, 2018
** Errors.hpp
** File description:
** Exersice 0 - Errors
*/

#ifndef ERRORS_HPP_
#define ERRORS_HPP_

#include <string>

class NasaError : public std::exception
{
    public:
        virtual ~NasaError() throw() { };
        NasaError(std::string const &message, std::string const &component);

        const std::string &getComponent() const;
        const char* what() const throw();
    protected:
        std::string _message;
        std::string _component;
};

class MissionCriticalError : public NasaError
{
    public:
        MissionCriticalError(std::string const &message, std::string const &component);
        virtual ~MissionCriticalError() throw() { };
};

class LifeCriticalError : public NasaError
{
    public:
        LifeCriticalError(std::string const &message, std::string const &component);
        virtual ~LifeCriticalError() throw() { };
};

class UserError : public NasaError
{
    public:
        UserError(std::string const &message, std::string const &component);
        virtual ~UserError() throw() { };
};

class CommunicationError : public NasaError
{
    public:
        CommunicationError(std::string const &message);
        virtual ~CommunicationError() throw() { };
};

#endif
