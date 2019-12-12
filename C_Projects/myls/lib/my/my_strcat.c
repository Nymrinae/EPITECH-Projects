/*
** EPITECH PROJECT, 2018
** my_strcat
** File description:
** This function concatenates two strings
*/

int    my_strlen(const char *str);

char    *my_strcat(char *dest, char const *src)
{
    int d = my_strlen(dest);
    int s = 0;

    while (src[s] != '\0')
    {
        dest[d] = src[s];
        d++;
        s++;
    }

    dest[d] = '\0';

    return (dest);
}