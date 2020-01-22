/*
** EPITECH PROJECT, 2018
** Cesar.hppww
** File description:
** Exersice 2 - Ave
*/

#ifndef _CESAR_H
#define _CESAR_H

#include <iostream>
#include "IEncryptionMethod.hpp"

class Cesar : public IEncryptionMethod {
    private:
        int _nb;

    public:
        Cesar();
        virtual ~Cesar() { };
        void encryptChar(char c);
        void decryptChar(char c);
        void reset();
};

#endif