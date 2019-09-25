/*
** EPITECH PROJECT, 2018
** strcapitalize
** File description:
** strcapitalize
*/

#include "my.h"

char *my_strcapitalize(char *str)
{
    int i = 0;
    int prev = 1;

    for (; str[i] != '\0'; i++) {
        if (prev && str[i] >= 'a' && str[i] <= 'z') {
            str[i] += 'A' - 'a';
            prev = 0;
        } else if (!prev && str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 'a' - 'A';
        else
            prev = !(is_alphanum(str[i]));
    }
    return (str);
}
