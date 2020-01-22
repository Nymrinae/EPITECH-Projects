/*
** EPITECH PROJECT, 2018
** OneTime.hpp
** File description:
** Exersice 2 - Ave
*/

#ifndef _ONETIME_H
#define _ONETIME_H

#include <string>
#include <iostream>

#include "IEncryptionMethod.hpp"

class OneTime : public IEncryptionMethod {
    protected:
        int _i;
        std::string _key;

    public:
        OneTime(const std::string &key);
        virtual ~OneTime() { };

        virtual void encryptChar(char c);
        virtual void decryptChar(char c);
        virtual void reset();
};

#endif