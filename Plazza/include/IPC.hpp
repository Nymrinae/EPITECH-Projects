/*
** EPITECH PROJECT, 2019
** Plazza
** File description:
** main.c
*/

#ifndef _IPC_H_
#define _IPC_H_

#include "Plazza.hpp"
#include "Busy.hpp"

class IPC {
    private:
        int _multiplier;
        int _cooks;
        int _refreshTime;
        char *_mem;
        int *_sMem;

    public:
        IPC(int, int, int);
        ~IPC() = default;

        inline int *getSmemory(void) const { return _sMem; }
        inline void setSmemory(int name, int size)
        {
          _sMem[0] = name;
          _sMem[1] = size;
        }
        void link(Busy &busy);
        void unlink();
};

#endif
