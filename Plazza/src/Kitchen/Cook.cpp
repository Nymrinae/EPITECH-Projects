/*
** EPITECH PROJECT, 2019
** Plazza
** File description:
** Thread.cpp
*/

#include <iostream>
#include <algorithm>
#include "Cook.hpp"

Cook::Cook(const std::size_t &cookNb) :
    _thread(cookNb, 0), _threadControl(0)
{}

bool Cook::resetCook(HandleCookT &hCook) const
{
    if (hCook._taskOk && hCook._itCook == _thread.size()) {
        hCook._itCook = 0;
        auto tmpFunctor = [](void) -> bool
        {
            return false;
        };
        generate(hCook._isRoll.begin(), hCook._isRoll.end(), tmpFunctor);
        return FAILURE;
    }
    return SUCCESS;
}

bool Cook::assignCook(HandleCookT &hCook)
{
    if (this->resetCook(hCook) == FAILURE)
        return FAILURE;
    hCook._taskOk = false;
    if (pthread_create(&_thread[hCook._itCook],
    NULL, &workInProgress, &hCook) != 0) {
        std::cerr << "[ERROR] Thread creation failed" << std::endl;
        exit(84);
    }
    if (pthread_create(&_threadControl, NULL,
    &manageCook, &hCook) != 0) {
        std::cerr << "[ERROR] Thread control creation failed" << std::endl;
        exit(84);
    };
    pthread_join(_thread[hCook._itCook], NULL);
    pthread_join(_threadControl, NULL);
    //std::cout << hCook._itCook << std::endl;
    hCook._itCook++;
    return SUCCESS;
}
