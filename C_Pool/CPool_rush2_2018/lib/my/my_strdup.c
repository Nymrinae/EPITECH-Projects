/*
** EPITECH PROJECT, 2018
** strdup
** File description:
** strdup
*/

#include "my.h"

char *my_strdup(char const *src)
{
    int len = my_strlen(src);
    char *new;

    new = malloc(sizeof(char) * len + 1);
    my_strcpy(new, src);
    return (new);
}
