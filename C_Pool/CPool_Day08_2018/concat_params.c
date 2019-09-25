/*
** EPITECH PROJECT, 2018
** concat_params.c
** File description:
** Turns the command-line given args into a single string
*/

#include <stdlib.h>
#include "include/my.h"

char *concat_params(int argc, char **argv)
{
    int length = 0;
    char *str;

    for (int i = 0; i < argc; i++) {
        length += my_strlen(argv[i]) + 1;
    }
    str = malloc(length * sizeof(char));
    if (str == NULL)
        return NULL;
    str = my_strcpy(str, argv[0]);
    for (int j = 1; j < argc; j++) {
        my_strcat(str, "\n");
        my_strcat(str, argv[j]);
    }
    return (str);
}