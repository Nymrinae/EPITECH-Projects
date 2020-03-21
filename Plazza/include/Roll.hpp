/*
** EPITECH PROJECT, 2019
** Plazza
** File description:
** Roll.hpp
*/

#pragma once

#include <pthread.h>

class Roll {
public:
    explicit Roll();
    ~Roll();
    void assignCook(void);
    void waitingForTheRoll(pthread_mutex_t *lock);
private:
    pthread_cond_t _roll;
};
