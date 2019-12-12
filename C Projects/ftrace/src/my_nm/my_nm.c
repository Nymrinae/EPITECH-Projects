/*
** EPITECH PROJECT, 2019
** ftrace
** File description:
** my_nm.h
*/

#include "my_nm.h"

int my_nm(int ac, char **av)
{
    int fd;
    int filesize;
    void *data;

    for (int i = 1; i < ac; i++) {
        if ((fd = open(av[i], O_RDONLY)) == -1)
            print_err(av[i], 0);
        filesize = lseek(fd, 0, SEEK_END);
        data = mmap(NULL, filesize, PROT_READ, MAP_PRIVATE, fd, 0);
        if (data == NULL)
            perror("mmap");
        else
            run_nm(av[i], data);
    }
    close(fd);

    return 0;
}

int run_nm(char *file, void *data)
{
    Elf64_Shdr *shdr;
    Elf64_Ehdr *ehdr = (Elf64_Ehdr *)(data);

    if (!memcmp(ehdr->e_ident, ELFMAG, SELFMAG)) {
        shdr = (Elf64_Shdr *)(data + ehdr->e_shoff);
        get_symbol(ehdr, shdr, data);
    } else
        print_err(file, 1);
}