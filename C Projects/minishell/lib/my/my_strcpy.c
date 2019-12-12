/*
** EPITECH PROJECT, 2018
** MY_STRCPY
** File description:
** Copies a string into another.
*/

char *my_strcpy(char *dest, char const *src)
{
    char i = 0;

    for (i = 0; src[i] != '\0'; i++) {
        dest[i] = src[i];
    }

    return (dest);
}
