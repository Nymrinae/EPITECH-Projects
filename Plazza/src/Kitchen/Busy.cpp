/*
** EPITECH PROJECT, 2019
** Plazza
** File description:
** Oven.cpp
*/

#include <iostream>
#include "Busy.hpp"

Busy::Busy() : _sharedMem(nullptr), _isShared(false)
{
    if (pthread_mutex_init(&_lock, NULL) != 0) {
        std::cerr << "Mutex init failed" << std::endl;
        exit(84);
    }
}

Busy::Busy(pthread_mutex_t *memory) : _sharedMem(memory), _isShared(true)
{}

void Busy::setSharedMem(pthread_mutex_t *sharedMem)
{
    _sharedMem = sharedMem;
    if (pthread_mutexattr_init(&_attr) != 0) {
        std::cerr << "Mutex set attributes failed" << std::endl;
        exit(84);
    }
    if (pthread_mutexattr_setpshared(&_attr, PTHREAD_PROCESS_SHARED) != 0) {
        std::cerr << "Mutex attributes share failed" << std::endl;
        exit(84);
    }
    if (pthread_mutex_init(_sharedMem, &_attr) != 0) {
        std::cerr << "Mutex init failed" << std::endl;
        exit(84);
    }
}

void Busy::doNotDisturb(void)
{
    if (!_isShared)
        pthread_mutex_lock(&_lock);
    else
        pthread_mutex_lock(_sharedMem);
}

void Busy::avaible(void)
{
    if (!_isShared)
        pthread_mutex_unlock(&_lock);
    else
        pthread_mutex_unlock(_sharedMem);
}

Busy::~Busy()
{
    if (_isShared)
        pthread_mutexattr_destroy(&_attr);
    pthread_mutex_destroy(&_lock);
}
