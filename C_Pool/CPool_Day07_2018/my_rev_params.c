/*
** EPITECH PROJECT, 2018
** my_rev_params.c
** File description:
** Displays main args in reverse order
*/

#include <unistd.h>

void my_putchar(char c);

int my_putstr(char const *str);

int main(int argc, char **argv)
{
    while (argc > 0){
        argc--;
        my_putstr(argv[argc]);
        my_putchar('\n');
    }
    return (0);
}