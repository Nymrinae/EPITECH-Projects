/*
** EPITECH PROJECT, 2018
** my_str_to_word_array
** File description:
** Split a string into words && returns an array.
*/

#include "../../include/my.h"
#include <stdlib.h>

int my_is_alpha(char c)
{
    if ((c >= 'A' && c <= 'Z') ||
    (c >= 'a' && c <= 'z') ||
    (c >= '0' && c <= '9')) {
        return (1);
    }
    return (0);
}

int my_count_words(const char *str)
{
    int c = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (my_is_alpha(str[i]) && !my_is_alpha(str[i + 1])) {
            c++;
        }
    }
    return (c);
}

char **my_str_to_word_array(char const *str)
{
    char **dest = malloc(sizeof(char *) * (my_count_words(str) + 1));
    int length = 0;
    int j = 0;

    if (dest == NULL)
        return NULL;

    for (int i = 0; str[i]; i++) {
        if (my_is_alpha(str[i]))
            length++;
        if (my_is_alpha(str[i]) && !my_is_alpha(str[i + 1])) {
            dest[j] = my_strncpy(dest[j], &str[i - length + 1], length);
            j++;
            length = 0;
        }
    }
    dest[j] = NULL;
    return (dest);
}
