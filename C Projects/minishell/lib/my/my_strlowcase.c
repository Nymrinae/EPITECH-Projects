/*
** EPITECH PROJECT, 2018
** my_strlowcase
** File description:
** My strlowcase
*/

#include <unistd.h>

char *my_strlowcase(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] >= 'A') && (str[i] <= 'Z'))
            str[i] = str[i] + 32;
    }
    return (str);
}
