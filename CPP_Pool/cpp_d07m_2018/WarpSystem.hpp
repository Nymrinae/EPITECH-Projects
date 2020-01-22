/*
** EPITECH PROJECT, 2018
** WarpSystem.cpp
** File description:
** Exersice 2 - Get Moving!
*/

#ifndef _WARPSYSTEM_H
#define _WARPSYSTEM_H

#include <string>
#include <algorithm>
#include <iostream>
#include <fstream>

namespace WarpSystem {

    class QuantumReactor {
        private:
        bool _stability;

        public:
        QuantumReactor();
        ~QuantumReactor();

        bool isStable();
        void setStability(bool stability);   
    };

    class Core {
        private:
        QuantumReactor *_coreReactor;

        public:
        Core(QuantumReactor *_codeReactor);
        ~Core();

        QuantumReactor *checkReactor();
    };
}
#endif