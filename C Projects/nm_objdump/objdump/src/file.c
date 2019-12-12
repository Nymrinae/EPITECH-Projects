/*
** EPITECH PROJECT, 2019
** objdump
** File description:
** file.c
*/

#include "objdump.h"

int is_elf(char *e)
{
    return (e[EI_MAG0] == 0x7f
            && e[EI_MAG1] == 'E'
            && e[EI_MAG2] == 'L'
            && e[EI_MAG3] == 'F');
}

int check_file(elf_t *elf)
{
    if (!is_elf(elf->ehdr->e_ident)){
        fprintf(stderr, "%s: File format not recognized\n", elf->file);
        return 84;
    }
    elf->shdr = (void *)elf->ehdr + elf->ehdr->e_shoff;
    if ((void *)elf->shdr > elf->maxsize
        || (void *)STRTAB > elf->maxsize){
            fprintf(stderr, "Error : invalid file\n");
            return (84);
        }
    elf->strtab = (char *)STRTAB;
    return (1);
}

int open_file(char *file, elf_t *elf)
{
    int fd;
    void *buff;

    elf->file = file;
    if ((fd = open(file, O_RDONLY)) == -1){
        perror(file);
        return 84;
    }
    elf->size = lseek(fd, 0, SEEK_END);
    if (elf->size == (unsigned int)-1){
        perror("lseek");
        return 84;
    }
    elf->ehdr = mmap(NULL, elf->size, PROT_READ, MAP_PRIVATE, fd, 0);
    if (elf->ehdr == (void *)-1){
        perror("mmap");
        return 84;
    }
    elf->maxsize = (void *)elf->ehdr + elf->size;
    return (check_file(elf));
}