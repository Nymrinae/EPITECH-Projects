/*
** EPITECH PROJECT, 2018
** my_rev_params
** File description:
** This function displays reverserd arguments
*/

#include "my_putchar.c"
#include "my_putstr.c"

int    my_putstr(const char *str);

int    main(int argc, char **argv)
{
    int i = argc - 1;

    while (i >= 0)
    {
        my_putstr(argv[i]);
        my_putchar('\n');
        i--;
    }

    return (0);
}