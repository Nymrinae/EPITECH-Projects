/*
** EPITECH PROJECT, 2018
** MY_REVSTR
** File description:
** Reverses a string.
*/

char *my_revstr(char *str)
{
    int swap;
    int i = 0;
    int j = 0;
    int size = 0;

    while (str[size] != '\0') {
        size++;
    }

    j = size - 1;

    for (i = 0; i != size / 2; i++) {
        swap = str[i];
        str[i] = str[j];
        str[j] = swap;
        j--;
    }

    return (str);
}
