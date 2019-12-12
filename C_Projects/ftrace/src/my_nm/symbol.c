/*
** EPITECH PROJECT, 2019
** ftrace
** File description:
** my_nm.h
*/

#include "my_nm.h"

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