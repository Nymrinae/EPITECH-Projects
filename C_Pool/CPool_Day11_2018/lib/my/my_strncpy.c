/*
** EPITECH PROJECT, 2018
** my_strncpy
** File description:
** Copies n characters from a  string into another
*/

#include <stdlib.h>

char *my_strncpy(char *dest, const char *src, int n)
{
    int i = 0;

    dest = malloc(sizeof(char) * (n + 1));
    while (n > 0 && src[i]) {
        dest[i] = src[i];
        n--;
        i++;
    }
    dest[i] = '\0';

    return (dest);
}
