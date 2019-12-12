/*
** EPITECH PROJECT, 2019
** strace
** File description:
** main.c
*/

#include "strace.h"

int main(int ac, char **av)
{
    if (no_args(ac))
        return 84;
    else if (!strcmp(av[1], "--help"))
        return usage(0);
    else
        return run_strace(av);
}

int run_strace(char **av)
{
    if (!strcmp(av[1], "-p") && av[2])
        return (strace_p(av));
    else
        strace(av);

    return (0);
}
