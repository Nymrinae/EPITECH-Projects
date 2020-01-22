/*
** EPITECH PROJECT, 2018
** Borg.hpp
** File description:
** Exersice 2 - Get Moving!
*/

#ifndef _BORG_H
#define _BORG_H

#include <iostream>
#include <fstream>
#include <string>
#include "Federation.hpp"
#include "WarpSystem.hpp"
#include "Destination.hpp"

namespace Borg {
    
    class Ship {
        private:
        int _side;
        short _maxWarp;
        Destination _home;
        Destination _location;
        WarpSystem::Core *_coreReactor;

        public:
        Ship();
        ~Ship();

        void setupCore(WarpSystem::Core* core);
        void checkCore();
        bool move();
        bool move(int warp);
        bool move(Destination d);
        bool move(int warp, Destination d);
    };
}

#endif