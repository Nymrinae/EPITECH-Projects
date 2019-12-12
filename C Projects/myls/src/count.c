/*
** EPITECH PROJECT, 2018
** count.c
** File description:
** count something
*/

#include "../include/my_ls.h"

int count_no_opt(char **av)
{
    int i = 1;
    int n = 0;

    while (av[i]) {
        if (av[i][0] != '-')
            n++;
        i++;
    }
    return ((n == 0) ? -1 : n);
}

int count_files(char *p)
{
    DIR *dir;
    struct dirent *directory;
    int i = 0;

    dir = opendir(p);
    while ((directory = readdir(dir)) != NULL) {
        if (directory->d_name[0] != '.')
            ++i;
    }
    return (i);
}