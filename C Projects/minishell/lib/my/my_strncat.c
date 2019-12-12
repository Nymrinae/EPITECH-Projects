/*
** EPITECH PROJECT, 2018
** MY_STRNCAT
** File description:
** Concatenates n characters of the src string to the end of the dest string.
*/

char *my_strncat(char *dest, char const *src, int nb)
{
    int i = 0;
    int j = 0;

    for (i = 0; src[j] != src[nb]; i++) {
        if (dest[i] == '\0')
        {
            dest[i] = src[j];
            j++;
        }
    }
}
