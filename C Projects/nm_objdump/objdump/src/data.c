/*
** EPITECH PROJECT, 2019
** objdump
** File description:
** data.c
*/

#include "objdump.h"

void print_hex(uint8_t *data, int size)
{
    for (int i = 0; i < 16; i++){
        printf((i < size ? "%02x" : "  "), data[i]);
        if (!((i + 1) % 4))
            printf(" ");
    }
    printf(" ");
}

void print_ascii(uint8_t *data, int size)
{
    for (int i = 0; i < 16; i++){
        printf((i < size)
                ? "%c"
                : "  ", IS_PRINTABLE(data[i]) ? data[i] : '.');
    }
    printf("\n");
}

void print_datas(elf_t *elf, int i)
{
    int j;
    int size;

    j = elf->shdr[i].sh_offset;
    size = elf->shdr[i].sh_offset + elf->shdr[i].sh_size;
    while ((unsigned int)j < size){
        printf(" %04x ", elf->shdr[i].sh_addr + j - elf->shdr[i].sh_offset);
        print_hex((unsigned char *)elf->ehdr + j, size - j);
        print_ascii((unsigned char *)elf->ehdr + j, size - j);
        j += 16;
    }
}

int check_section(char *name)
{
    return (strlen(name) != 0
        && strcmp(name, ".strtab")
        && strcmp(name, ".symtab")
        && strcmp(name, ".shstrtab")
        && strcmp(name, ".bss"));
}

void write_data(elf_t *elf)
{
    int i = 1;
    char *name;
    int num = elf->ehdr->e_shnum;

    while (i < num) {
        name = &elf->strtab[elf->shdr[i].sh_name];
        if (check_section(name)) {
            printf("Contents of section %s:\n", name);
            print_datas(elf, i);
        }
        i++;
    }
}