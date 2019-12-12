/*
** EPITECH PROJECT, 2018
** functions.c
** File description:
** functions used for my_ls
*/

#include "../include/my_ls.h"

void get_option(char **av, struct opt *options, int i, int j)
{
    while (av[i][j]) {
        ++j;
        switch(av[i][j]) {
            case 'l': options->opt_l = 1; break;
            case 'R': options->opt_R = 1; break;
            case 'r': options->opt_r = 1; break;
            case 'd': options->opt_d = 1; break;
            case 't': options->opt_t = 1; break;
        }
    }
}

int *args_parser(char **av, struct opt *options, int dir)
{
    int j = 0;
    int n = 0;
    int *path = NULL;

    if (dir != -1) {
        if ((path = malloc(dir * sizeof(int))) == NULL)
            exit (84);
    }
    for (int i = 1; av[i]; i++) {
        if (av[i][j] == '-')
            get_option(av, options, i, j);
        else if (dir != -1 || dir != 0) {
            path[n] = i;
            n++;
            dir--;
        }
        j = 0;
    }
    return (path);
}