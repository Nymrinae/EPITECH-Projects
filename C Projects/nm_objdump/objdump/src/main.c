/*
** EPITECH PROJECT, 2019
** objdump
** File description:
** main.c
*/

#include "objdump.h"

int main(int ac, char **av)
{
    elf_t elf;

    for (int i = 1; i < ac; i++) {
        if (open_file(ac == 1 ? "a.out" : av[i], &elf) != 84){
            write_header(&elf);
            write_data(&elf);
        } else
            return 84;
    }
    return (0);
}