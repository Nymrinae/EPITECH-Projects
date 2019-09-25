/*
** EPITECH PROJECT, 2018
** strcpy
** File description:
** strcpy
*/

char *my_strcpy(char *dest, char const *source)
{
    int i;

    for (i = 0; source[i] != '\0'; i++)
        dest[i] = source[i];
    dest[i] = '\0';
    return (dest);
}
