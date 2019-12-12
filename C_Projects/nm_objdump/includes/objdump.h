/*
** EPITECH PROJECT, 2019
** objdump
** File description:
** objdump.h
*/

#ifndef OBJDUMP_H_
#define OBJDUMP_H_

#include <elf.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>

#define FF "elf64-x86-64"

// Machines
#define NONE "None"
#define M32 "WE32100"
#define I80386 "Intel 80386"
#define M68K "Motorola 68000"
#define M88K "Motorola 88000"
#define I80860 "Intel 80860"
#define MRS "MIPS RS3000"
#define HPPA "HPPA"
#define PPC "PowerPC"
#define PPC64 "PowerPC64"
#define IBMS390 "IBM S/390"
#define ARM "ARM"
#define RSH "Renesas SuperH"
#define SV9 "Sparc v9"
#define IA64 "Intel IA-64"
#define VAX "DEC Vax"
#define X8664 "i386:x86-64"

#define IS_PRINTABLE(x) (x >= ' ' && x <= '~')
#define STRTAB (void *)elf->ehdr + elf->shdr[elf->ehdr->e_shstrndx].sh_offset

// __ Structs __
typedef struct elf
{
    char            *file;
    char            *strtab;
    void            *maxsize;
    Elf64_Ehdr      *ehdr;
    Elf64_Shdr      *shdr;
    unsigned int    size;
} elf_t;

// __ Prototypes __

// Get Infos
int     get_flags(elf_t *);
int     check_section(char *);
char    *get_machine_type(elf_t *, char *);

// Write Infos
void    write_header(elf_t *);
void    write_data(elf_t *);

// Print Infos
void    print_hex(uint8_t *, int);
void    print_ascii(uint8_t *, int);
void    print_datas(elf_t *, int);

// Functions
int     is_elf(char *);
int     check_file(elf_t *);
int     open_file(char *file, elf_t *);

#endif