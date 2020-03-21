/*
** EPITECH PROJECT, 2019
** Plazza
** File description:
** Mutex.hpp
*/

#pragma once

#include <pthread.h>
#include <string>

class Busy {
public:
    explicit Busy();
    Busy(pthread_mutex_t *memory);
    ~Busy();
    inline pthread_mutex_t *getLock(void) { return &_lock; }
    void setSharedMem(pthread_mutex_t *sharedMem);
    // { _sharedMem = sharedMem; }
    void doNotDisturb(void);
    void avaible(void);
    // Busy &operator=(const Busy &busyCpy)
    // {
    //     if (this != &busyCpy) {
    //         _lock = busyCpy._lock;
    //         _sharedMem = busyCpy._sharedMem;
    //         _attr = busyCpy._attr;
    //         _isShared = busyCpy._isShared;
    //     }
    //     return *this;
    // }
private:
    pthread_mutex_t _lock;
    pthread_mutex_t *_sharedMem;
    pthread_mutexattr_t _attr;
    bool _isShared;
};
