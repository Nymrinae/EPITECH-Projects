/*
** EPITECH PROJECT, 2018
** sort.c
** File description:
** Sort arrays
*/

#include "../include/my_ls.h"

void sort_tab(char **tab, int n, struct opt options)
{
    char *tmp;

    for (int i = 1; i <= n - 1; i++) {
        for (int j = 0; j <= n - i - 1; j++) {
            if ((options.opt_r)
                ? (my_strcmp(tab[j], tab[j + 1]) < 0)
                : (my_strcmp(tab[j], tab[j + 1]) > 0)) {
                tmp = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = tmp;
            }
        }
    }
}

void sort_time(char **tab, int n, struct opt options)
{
    char *tmp;
    for (int i = 1; i <= n - 1; i++) {
        for (int j = 0; j <= n - i - 1; j++) {
            if ((options.opt_l)
                ? (get_mtime(tab[i]) > get_mtime(tab[j]))
                : (get_mtime(tab[i]) < get_mtime(tab[j]))) {
                tmp = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = tmp;
            }
        }
    }
}