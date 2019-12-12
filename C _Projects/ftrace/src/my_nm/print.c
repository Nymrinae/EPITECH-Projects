/*
** EPITECH PROJECT, 2019
** ftrace
** File description:
** my_nm.h
*/

#include "my_nm.h"

void print_err(char *str, int type)
{
    char buff[512];
    char nofile[48] = "No such file\n";
    char fileerr[48] = "File format not recognized\n";

    sprintf(buff, "my_nm: '%s': %s", str, !type ? nofile : fileerr);
    fprintf(stderr, "%s", buff);
    exit(84);
}

int print_symbolname(Elf64_Shdr *shdr, void *data,
Elf64_Shdr *symtab, Elf64_Shdr *strtab)
{
    char c;
    char *str = (char *)(data + strtab->sh_offset);
    size_t size = symtab->sh_size / sizeof(Elf64_Sym);
    Elf64_Sym *sym = (Elf64_Sym *)(data + symtab->sh_offset);

    for (size_t i = 0; i < size; i++) {
        c = cs_symbol(sym[i], shdr);
        if (sym[i].st_name && (c == 'T' || c == 'U'))
            printf("Entering function %s at %p\n", str + sym[i].st_name, sym[i].st_value);
    }
}

char cs_symbol(Elf64_Sym sym, Elf64_Shdr *shdr)
{
    char c;

    if (ELF64_ST_BIND(sym.st_info) == STB_GNU_UNIQUE)
        c = 'u';
    else if (sym.st_shndx == SHN_UNDEF)
        c = 'U';
    else
        c = get_nextsymbol(sym, shdr);
    if (ELF64_ST_BIND(sym.st_info) == STB_LOCAL && c != '?')
        c += 32;
    return c;
}

char get_nextsymbol(Elf64_Sym sym, Elf64_Shdr *shdr)
{
    char c;

    if (sym.st_shndx == SHN_ABS)
        c = 'A';
    else if (shdr[sym.st_shndx].sh_type == SHT_PROGBITS
        && shdr[sym.st_shndx].sh_flags == (SHF_ALLOC | SHF_EXECINSTR))
        c = 'T';
    else
        c = '?';
    return c;
}