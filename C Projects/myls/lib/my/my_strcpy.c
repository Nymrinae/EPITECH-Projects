/*
** EPITECH PROJECT, 2018
** my_strcpy
** File description:
** This function copie a string into another
*/

char *my_strcpy(char *dest, char const *src)
{
    int idx = 0;

    while (src[idx] != '\0')
    {
        dest[idx] =  src[idx];
        idx++;
    }

    dest[idx] = '\0';

    return (dest);
}