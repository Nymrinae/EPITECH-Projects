/*
** EPITECH PROJECT, 2018
** my_strdup.c
** File description:
** Allocates memory and copies the string given as arg in it
*/

#include <stdlib.h>
#include "include/my.h"


char *my_strdup(char const *src)
{
    int src_len = my_strlen(src) + 1;
    char *newstr = malloc(src_len * sizeof(char));
    
    newstr = my_strcpy(newstr, src);
    newstr[src_len - 1] = '\0';
    return (newstr);
}
