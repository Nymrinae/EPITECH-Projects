/*
** EPITECH PROJECT, 2018
** .cpp
** File description:
** ???
*/

#ifndef _DROID_H
#define _DROID_H

#include <iostream>
#include <string>

class Droid {
    private:
        std::string _id;
        size_t _energy;
        const size_t _atk;
        const size_t _tough;
        std::string *_status;

        void speak(std::string msg);

    public:
        Droid(std::string id = "");
        Droid(Droid &droid);
        ~Droid();

        std::string getId()         const { return this->_id; };
        size_t getEnergy()          const { return this->_energy; };
        size_t getAttack()          const { return this->_atk; };
        size_t getToughness()       const { return this->_tough; };
        std::string *getStatus()    const { return this->_status; };

        void setId(std::string id) { this->_id = id; };
        void setEnergy(size_t energy) { this->_energy = energy; };
        void setStatus(std::string *status) { this->_status = status;};

        Droid& operator=  (Droid const &droid);
        bool operator== (const Droid &droid) const;
        bool operator!= (const Droid &droid) const;
        Droid& operator<< (size_t &energy);
};

std::ostream &operator<<(std::ostream &os, Droid const &droid);

#endif