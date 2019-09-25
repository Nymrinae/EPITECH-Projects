/*
** EPITECH PROJECT, 2018
** main
** File description:
** rush2
*/

#include "rush2.h"

int main(int ac, char **av)
{
    int i;
    int occ;
    char letter;
    int freq;

    if (ac >= 3) {
        for (i = 2; i < ac; i++) {
            letter = *(av[i]);
            occ = occurences(av[1], letter, &freq);
            print_letter(occ, letter, freq);
        }
    }
    if (ac >= 2)
        guess_language(av[1]);
    else
        return (84);
    return (0);
}
