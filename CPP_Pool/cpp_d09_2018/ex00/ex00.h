/*
** EPITECH PROJECT, 2018
** ex00.h
** File description:
** Exersice 0 - Back to BasiCs
*/

// Struct Declaration

#include <stdlib.h>
#include <stdio.h>

typedef struct s_cthulhu {
    int m_power;
    char *m_name;
} cthulhu_t;

typedef struct s_koala {
    cthulhu_t m_parent;
    char m_is_a_legend;
} koala_t;

// Prototypes
cthulhu_t   *new_cthulhu(void);
void        print_power(cthulhu_t *this);
void        attack(cthulhu_t *this);
void        sleeping(cthulhu_t *this);

koala_t     *new_koala(char *name, char is_a_legend);
void        eat(koala_t *this);