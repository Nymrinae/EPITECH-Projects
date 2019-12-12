/*
** EPITECH PROJECT, 2019
** objdump
** File description:
** header.c
*/

#include "objdump.h"

int get_flags(elf_t *elf)
{
    int flags = 0;

    switch(elf->ehdr->e_type) {
        case 1: printf("HAS_RELOC, "); flags++; break;
        case 2: printf("EXEC_P, "); flags++; break;
        case 3: printf("HAS_SYMS, DYNAMIC, "); flags++; break;
    }
    for (int i = 0; i < elf->ehdr->e_shnum; i++)
        if (elf->shdr[i].sh_type == SHT_SYMTAB
            && elf->ehdr->e_type != 3) {
            printf("HAS_SYMS, ");
            flags++;
        }
    if (elf->ehdr->e_phnum > 0){
        printf("D_PAGED ");
        flags++;
    }
    return (flags);
}

char *get_machine_type(elf_t *elf, char *archi)
{
    switch(elf->ehdr->e_machine){
        case 0:  archi = NONE;      break;
        case 1:  archi = M32;       break;
        case 2:  archi = I80386;    break;
        case 3:  archi = M68K;      break;
        case 4:  archi = M88K;      break;
        case 7:  archi = I80860;    break;
        case 8:  archi = MRS;       break;
        case 15: archi = HPPA;      break;
        case 20: archi = PPC;       break;
        case 21: archi = PPC64;     break;
        case 22: archi = IBMS390;   break;
        case 40: archi = ARM;       break;
        case 42: archi = RSH;       break;
        case 43: archi = SV9;       break;
        case 50: archi = IA64;      break;
        case 75: archi = VAX;       break;
        default: archi = X8664;     break;
    }
    return (archi);
}

void write_header(elf_t *elf)
{
    char *archi = get_machine_type(elf, archi);

    printf("\n%s:     file format %s\n", elf->file, FF);
    printf("architecture: %s, flags 0x%08x:\n", archi, elf->ehdr->e_flags);
    if (get_flags(elf) > 0)
        printf("\n");
    printf("start address 0x%016x\n\n", elf->ehdr->e_entry);
}