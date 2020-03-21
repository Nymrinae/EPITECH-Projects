/*
** EPITECH PROJECT, 2019
** plazza
** File description:
** Roll.cpp
*/

#include <iostream>
#include "Roll.hpp"

Roll::Roll()
{
    pthread_condattr_t attr;

    if (pthread_cond_init(&_roll, &attr) != 0) {
        std::cerr << "Mutex init failed" << std::endl;
        exit(84);
    }
}

void Roll::assignCook(void)
{
    pthread_cond_signal(&_roll);
}

void Roll::waitingForTheRoll(pthread_mutex_t *lock)
{
    pthread_cond_wait(&_roll, lock);
}

Roll::~Roll()
{
    pthread_cond_destroy(&_roll);
}
