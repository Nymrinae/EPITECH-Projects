/*
** EPITECH PROJECT, 2019
** Plazza
** File description:
** Thread.c
*/

#ifndef _THREAD_H_
#define _THREAD_H_

#include <pthread.h>
#include <vector>
#include "CookUtility.hpp"

static const bool SUCCESS = true;
static const bool FAILURE = false;

class Cook {
public:
    explicit Cook(const std::size_t &cookNb);
    ~Cook() = default;
    bool assignCook(HandleCookT &hCook);
private:
    std::vector<pthread_t> _thread;
    pthread_t _threadControl;
    bool resetCook(HandleCookT &hCook) const;
};

#endif
