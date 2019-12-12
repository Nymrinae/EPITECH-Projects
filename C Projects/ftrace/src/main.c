/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main.c
*/

#include "my_nm.h"
#include "strace.h"

int main(int ac, char **av)
{
    if (ac != 2 || !strcmp(av[1], "--help")){
        printf("USAGE: ftrace <command>\n");
        return 84;
    } else {
        my_nm(ac, av);
        run_strace(av);
    }
    return (EXIT_SUCCESS);
}
