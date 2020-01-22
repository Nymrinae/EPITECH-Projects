/*
** EPITECH PROJECT, 2018
** Federation.hpp
** File description:
** Exersice 2 - Get Moving!
*/

#ifndef _FEDERATION_H
#define _FEDERATION_H

#include <string>
#include <algorithm>
#include <iostream>
#include <fstream>
#include "WarpSystem.hpp"
#include "Destination.hpp"

namespace Federation {

    namespace Starfleet {

        class Ensign {
            private:
            std::string _name;

            public:
            Ensign(std::string _name);
            ~Ensign();
        };

        class Captain {
            private:
            std::string _name;
            int _age;

            public:
            Captain(std::string _name);
            ~Captain();

            int         getAge();
            std::string getName();
            void        setAge(int age);
        };

        class Ship {
            private:
            int _length;
            int _width;
            std::string _name;
            short _maxWarp;
            Destination _home;
            Destination _location;
            WarpSystem::Core *_coreReactor;
            Federation::Starfleet::Captain *captain;

            public:
            Ship(int length, int width, std::string name, short maxWarp);
            ~Ship();

            void checkCore();
            void setupCore(WarpSystem::Core* core);
            void promote(Federation::Starfleet::Captain *captain);
            bool move();
            bool move(int warp);
            bool move(Destination d);
            bool move(int warp, Destination d);
        };
    }

    class Ship {
        private:
        int _length;
        int _width;
        std::string _name;
        short _maxWarp;
        Destination _home;
        Destination _location;
        WarpSystem::Core *_coreReactor;

        public:
        Ship(int length, int width, std::string name);
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