/*
** EPITECH PROJECT, 2018
** Picture.cpp
** File description:
** Exersice 2 - Simple inheritance
*/

#ifndef _TOY_H
#define _TOY_H

#include "Picture.hpp"

class Toy {

    public:
        //Enum Definition
        enum ToyType {
            BASIC_TOY,
            ALIEN,
            BUZZ,
            WOODY
        };

        // Nested Class (Part05)
        class Error {
            public:
                enum ErrorType {
                    UNKNOWN,
                    PICTURE,
                    SPEAK
                };

                ErrorType type;

                Error();
                void setType(ErrorType type);
                std::string what() const;
                std::string where() const;
        };

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

        //Others
        virtual bool speak(const std::string msg);
        virtual bool speak_es(const std::string msg);
        const Toy::Error &getLastError() const;
    
        Toy &operator=(Toy const &T);
        Toy &operator<<(std::string const &str);
    
    protected:
    // Attributes Definition
        ToyType _type;
        std::string _name;
        Picture _picture;
        Error err;
};

std::ostream& operator<<(std::ostream &os, Toy const &Toy);

#endif

