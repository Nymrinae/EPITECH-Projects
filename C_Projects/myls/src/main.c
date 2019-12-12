/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include "../include/my_ls.h"

int main(int ac, char **av)
{
    int i = 0;
    int *tab = NULL;
    int nb_dir = count_no_opt(av);
    struct opt options;

    init_options(&options);
    tab = args_parser(av, &options, nb_dir);

    if (nb_dir == -1)
        my_ls_no_arg(av, options);
    else if (nb_dir != - 1)
        my_ls(ac, av, options);
    else {
        my_putstr(av[ac - 1]);
        my_putchar('\n');
    }
    return (0);
}