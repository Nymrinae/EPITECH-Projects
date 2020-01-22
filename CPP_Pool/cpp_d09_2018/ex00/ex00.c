/*
** EPITECH PROJECT, 2018
** ex00.c
** File description:
** Exersice 0 - Back to BasiCs
*/

#include "ex00.h"

static void koala_initializer(koala_t *this, char *_name, char _is_A_Legend);
static void cthulhu_initializer(cthulhu_t *this);

// __________ L'AUTRE FILS DE PUTE DE CTHULHU  __________ //

cthulhu_t *new_cthulhu()
{
    cthulhu_t *c = malloc(sizeof(cthulhu_t));

    cthulhu_initializer(c);
    printf("----\n");
    printf("Building %s\n", c->m_name);

    return (c);
}

static void cthulhu_initializer(cthulhu_t *this)
{
    this->m_name = "Cthulhu";
    this->m_power = 42;
}

void print_power(cthulhu_t *this)
{
    printf("Power => %d\n", this->m_power);
}

void attack(cthulhu_t *this)
{
    if (this->m_power >= 42) {
        this->m_power -= 42;
        printf("%s attacks and destroys the city\n", this->m_name);
    } else 
        printf("%s can't attack, he doesn't have enough power\n", this->m_name);
}

void sleeping(cthulhu_t *this)
{
    this->m_power += 42000;
    printf("%s sleeps\n", this->m_name);
}
// _______________________ KOALA _______________________ //

koala_t *new_koala(char *name, char is_a_legend)
{
    koala_t *koala = malloc(sizeof(koala_t));

    koala_initializer(koala, name, is_a_legend);
    printf("----\n");
    printf("Building Cthulhu\n");
    printf("Building %s\n", name);

    return (koala);
}

static void koala_initializer(koala_t *this, char *_name, char _is_A_Legend)
{
    this->m_parent.m_name = _name;
    this->m_is_a_legend = _is_A_Legend;
    if (this->m_is_a_legend)
        this->m_parent.m_power = 42;
}

void eat(koala_t *this)
{
    this->m_parent.m_power += 42;
    printf("%s eats\n", this->m_parent.m_name);
}