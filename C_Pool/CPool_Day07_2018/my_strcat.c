/*
** EPITECH PROJECT, 2018
** my_strcat
** File description:
** Concatenate src string to dest string
*/

int my_strlen(char const *str);

char *my_strcat(char *dest, char const *src)
{
    int l = my_strlen(dest);
    int i = 0;

    while (src[i] != '\0') {
        dest[l + i] = src[i];
        i++;
    }
    dest[l + i] = '\0';
    return (dest);
}
