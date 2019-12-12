/*
** EPITECH PROJECT, 2018
** my_strncpy
** File description:
** This function copie n char
** from a string into another
*/

char    *my_strncpy(char *dest, char *src, int n)
{
    int idx = 0;

    while (idx < n && src[idx] != '\0') {
        dest[idx] = src[idx];
        idx++;
    }
    dest[idx] = '\0';

    return (dest);
}