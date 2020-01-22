/*
** EPITECH PROJECT, 2018
** string_split.c
** File description:
** Exercise 13 - Split
*/

#include "string.h"

string_t **split_s(const string_t *this, char seperator)
{

}

char **split_c(const string_t *this, char seperator)
{
    char *str = strdup(this->str);
    char tok[2];
    char **tab;
    int i = 0;

    tok[0] = seperator;
    tok[1] = 0;
    strtok(str, tok);
    while (strtok(NULL, tok))
        i++;
    tab = malloc((i + 1) * sizeof(char **));
    free(str);
    str = strdup(this->str);
    tab[0] = strtok(str, tok);
    i = 1;
    while ((tab[i++] = strtok(NULL, tok)));

    return (tab);
}