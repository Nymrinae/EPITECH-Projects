/*
** EPITECH PROJECT, 2018
** KoalaBot.hpp
** File description:
** Exersice 1 - Koala Bot
*/

#ifndef _KOALABOT_H
#define _KOALABOT_H

#include "Parts.hpp"

class KoalaBot {
    private:
        std::string _serial;
        Head _head;
        Arms _arms;
        Legs _legs;

    public:
        KoalaBot(std::string serial = "Bob-01");
        ~KoalaBot();

        void setParts(Head head);
        void setParts(Arms arms);
        void setParts(Legs legs);

        void swapParts(Head &head);
        void swapParts(Arms &arms);
        void swapParts(Legs &legs);

        void informations();
        bool status();
};

#endif