/*
** EPITECH PROJECT, 2018
** my_ls
** File description:
** my_ls
*/

#include "../include/my_ls.h"

int my_ls_no_arg(char **av, struct opt options)
{
    char **index;
    int nb_files = count_files(".");

    if (options.opt_d == 1)
        dir(".", options);
    else {
        index = fill_array_name(".", nb_files);
        sort_tab(index, nb_files, options);
        my_ls_print(index, ".", nb_files, options);
        free(index);
    }
    return (0);
}

int my_ls(int ac, char **av, struct opt options)
{
    struct stat sf;
    int err;

    stat(av[ac - 1], &sf);
    if (stat(av[ac - 1], &sf) < 0) {
        manage_errors(ac, av);
        return (84);
    }
    if (S_ISDIR(sf.st_mode) == 1)
        print_dir_content(av[ac - 1]);
    else if (options.opt_l > 0) {
        if (S_ISDIR(sf.st_mode) == 0) {
            print_stat(av[ac - 1]);
            parse_filename(av[ac - 1]);
        } else
            my_putstr(my_strcat(av[ac - 1], "\n"));
    }
    return (err);
}