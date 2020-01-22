/*
** EPITECH PROJECT, 2018
** KoalaBot.cpp
** File description:
** Exersice 1 - Koala Bot
*/

#include "KoalaBot.hpp"

KoalaBot::KoalaBot(std::string serial)
{
    this->_serial = serial;
}

KoalaBot::~KoalaBot() {}

void KoalaBot::setParts(Head head)
{
    this->_head = head;
}

void KoalaBot::setParts(Arms arms)
{
    this->_arms = arms;
}

void KoalaBot::setParts(Legs legs)
{
    this->_legs = legs;
}

void KoalaBot::swapParts(Head &head)
{
    setParts(head);
}

void KoalaBot::swapParts(Arms &arms)
{
    setParts(arms);
}

void KoalaBot::swapParts(Legs &legs)
{
    setParts(legs);
}

void KoalaBot::informations()
{
    std::cout << "[Koala Bot] " << this->_serial << std::endl;
    _arms.informations();
    _legs.informations();
    _head.informations();
}

bool KoalaBot::status()
{
    return (_head.isFunctionnal() && _arms.isFunctionnal() && _legs.isFunctionnal());
}