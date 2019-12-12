/*
** EPITECH PROJECT, 2018
** print.c
** File description:
** print.c
*/

#include "../include/my_ls.h"

void print_color(char *file)
{
    struct stat sf;

    stat(file, &sf);
    my_putchar(32);
    switch(sf.st_mode & __S_IFMT) {
        case (__S_IFDIR): my_putstr("\e[34m"); break;
        case (S_IXUSR): my_putstr("\e[32m"); break;
        case (__S_IFBLK || __S_IFCHR): my_putstr("\e[38;5;226;48;5;0"); break;
        case (__S_IFIFO): my_putstr("\e[38;5;11;48;5;0"); break;
        default: my_putstr("\e[97m"); break;
    }
    my_putstr(file);
    my_putstr("\e[39m");
}