/*
** EPITECH PROJECT, 2018
** strstr
** File description:
** strstr
*/

#include "my.h"

char *my_strstr(char *str, char const *to_find)
{
    int i = 0;
    int len = my_strlen(to_find);

    for (; str[i + len - 1] != '\0'; i++) {
        if (my_strncmp(str + i, to_find, len) == 0)
            return (str + i);
    }
    return (NULL);
}
