/*
** EPITECH PROJECT, 2018
** Picture.cpp
** File description:
** Exersice 0 : Encapsulation
*/

#ifndef _TOY_H
#define _TOY_H

#include "Picture.hpp"

class Toy {

    public:
        //Enum Definition
        enum ToyType {
            BASIC_TOY,
            ALIEN
        };
        
        // Attributes Definition
        ToyType _type;
        std::string _name;
        Picture _picture;

        // Constructor && Destructor
        Toy();
        Toy(Toy const &T);
        Toy(ToyType type, const std::string &name, const std::string &ascii);
        ~Toy() { };

        // Getters
        int getType() const;
        const std::string &getName() const;
        const std::string &getAscii() const;

        // Setters
        void setName(std::string const &name);
        bool setAscii(std::string const &filename);

        Toy operator=(const Toy &Toy);
};

#endif

