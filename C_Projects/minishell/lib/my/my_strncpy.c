/*
** EPITECH PROJECT, 2018
** MY_STRNCPY
** File description:
** Copies n characters from a string into another.
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    char i = 0;
    char j = 0;

    while (src[i] != '\0') {
        i++;
    }
    if (n > i)
        for (j = 0; src[j] != '\0'; j++) {
            dest[j] = src[j];
        }
    else
        for (j = 0; j < n; j++) {
            dest[j] = src[j];
        }

    return (dest + '\0');
}
