/*
** EPITECH PROJECT, 2018
** fct
** File description:
** functions 4 cat
*/

#include "../include/fct.h"
#include "../include/my.h"

void read_err(int errno)
{
    switch(errno) {
        case 2:
            my_putstr("No such file or directory");
            break;
        case 13:
            my_putstr("Permission denied");
            break;
        case 21:
            my_putstr("Can't read a directory");
            break;
        default:
            my_putstr("nik ta mere je gère pas l'erreur");
    }
}
