/*
** EPITECH PROJECT, 2018
** my_strncat
** File description:
** This function concatenates n char
*/

int    my_strlen(const char *str);

char    *my_strncat(char *dest, char const *src, int nb)
{
    int d = my_strlen(dest);
    int s = 0;

    while (src[s] != '\0' && s < nb)
    {
        dest[d] = src[s];
        d++;
        s++;
    }

    dest[d] = '\0';

    return (dest);
}