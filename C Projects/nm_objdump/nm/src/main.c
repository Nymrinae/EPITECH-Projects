/*
** EPITECH PROJECT, 2019
** nm
** File description:

** main.c
*/

#include "nm.h"

int main(int ac, char **av)
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

int get_symbol(Elf64_Ehdr *ehdr, Elf64_Shdr *shdr, void *data)
{
    Elf64_Shdr *symtab;
    Elf64_Shdr *strtab;
    Elf64_Shdr *shstrtab;
    char *str = (char *)(data + shdr[ehdr->e_shstrndx].sh_offset);

    for (int i = 1; i < ehdr->e_shnum; i++) {
        if (!strcmp(&str[shdr[i].sh_name], ".symtab"))
            symtab = (Elf64_Shdr *)&shdr[i];
        if (!strcmp(&str[shdr[i].sh_name], ".strtab"))
            strtab = (Elf64_Shdr *)&shdr[i];
        if (!strcmp(&str[shdr[i].sh_name], ".shstrtab"))
            shstrtab = (Elf64_Shdr *)&shdr[i];
    }
    print_symbolname(shdr, data, symtab, strtab);
}