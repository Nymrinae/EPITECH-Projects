/*
** EPITECH PROJECT, 2019
** ftrace
** File description:
** my_nm.h
*/

#ifndef _NM_H_
#define _NM_H_

#include <elf.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>

// my_nm.c
int     my_nm(int, char **);
int     run_nm(char *, void *);

// symbol.c
char    cs_symbol(Elf64_Sym, Elf64_Shdr *) ;
char    get_nextsymbol(Elf64_Sym, Elf64_Shdr *);
int     get_symbol(Elf64_Ehdr *, Elf64_Shdr *, void *);

// print.c
void    print_err(char *, int);
int     print_symbolname(Elf64_Shdr *, void *, Elf64_Shdr *, Elf64_Shdr *);

#endif

