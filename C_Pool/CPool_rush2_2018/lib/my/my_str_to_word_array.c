/*
** EPITECH PROJECT, 2018
** strtowordarray
** File description:
** strtowordarray
*/

#include "my.h"

int is_alphanum(char c)
{
    return ((c >= 'A' && c <= 'Z')
            || (c >= 'a' && c <= 'z')
            || (c >= '0' && c <= '9'));
}

static int str_array_size(char const *str)
{
    int size = 0;
    int i = 0;

    while (str[i] != '\0') {
        if (!is_alphanum(str[i]))
            ++size;
        ++i;
    }
    return (size + 1);
}

static char *create_entry(int prev, int i, char const *str)
{
    char *temp;

    temp = malloc(sizeof(char) * (i - prev + 1));
    if (temp != NULL) {
        my_strncpy(temp, str + prev, i - prev);
        temp[i - prev] = '\0';
    }
    return (temp);
}

char **my_str_to_word_array(char const *str)
{
    int i = 0;
    int j = 0;
    char **array;
    int prev = 0;

    array = malloc(sizeof(char *) * (str_array_size(str) + 1));
    if (array == NULL)
        return (array);
    for (; !is_alphanum(str[i]) && !(str[i] == '\0'); i++, prev++);
    for (; str[i] != '\0'; i++) {
        if (!is_alphanum(str[i])) {
            array[j] = create_entry(prev, i, str);
            ++j;
            prev = i;
        }
        for (; !is_alphanum(str[i]) && !(str[i] == '\0'); i++, prev++);
    }
    if (is_alphanum(str[i - 1])) {
        array[j] = create_entry(prev, i, str);
        ++j;
    }
    array[j + 1] = 0;
    return (array);
}
