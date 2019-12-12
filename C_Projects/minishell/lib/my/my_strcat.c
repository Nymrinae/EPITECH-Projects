/*
** EPITECH PROJECT, 2018
** MY_STRCAT
** File description:
** Concatenates two strings.
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    int j = 0;
    int i = 0;
    char *new_str = malloc(sizeof(char) * (my_strlen(dest) +
    my_strlen(src) - 1));

    for (j = 0; dest[j] != '\0'; j++) {
        new_str[j] = dest[j];
    }
    for (i = 0; src[i] !=  '\0'; i++) {
        new_str[i + j] = src[i];
    }
    new_str[i + j] = '\0';
    return (new_str);
}
