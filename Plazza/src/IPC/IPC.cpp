/*
** EPITECH PROJECT, 2019
** Plazza
** File description:
** main.c
*/

#include "IPC.hpp"

IPC::IPC(int m, int c, int s) :
_multiplier(m),
_cooks(c),
_refreshTime(s)
{
}

void IPC::link(Busy &busy)
{
    int handle = shm_open("/shm", O_CREAT | O_RDWR, 0777);

    ftruncate(handle, sizeof(int) * 2048);
    _mem = (char *)mmap(0, sizeof(int) * 2048, PROT_READ | PROT_WRITE, MAP_SHARED, handle, 0);
    busy.setSharedMem((pthread_mutex_t *)_mem);
    _sMem = (int *)(_mem + sizeof(pthread_mutex_t));
    *_sMem = 0;
}

void IPC::unlink()
{
    munmap((void *)&this->_mem, sizeof(int) * 2048);
    shm_unlink("/shm");
}

