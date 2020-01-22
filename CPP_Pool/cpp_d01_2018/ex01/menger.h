/*
** EPITECH PROJECT, 2018
** menger.h
** File description:
** Exercise 1 - The Menger Sponge
*/

#ifndef _MENGER_H_
#define _MENGER_H_

//Headers
#include <stdlib.h>
#include <stdio.h>

int     my_atoi(char *str);
int     menger(int size, int level);
int     do_menger(int size, int level, int x, int y);
void    run_menger(int size, int level, int x, int y);

#endif