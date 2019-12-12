/*
** EPITECH PROJECT, 2018
** home_path
** File description:
** home_path
*/

#include "mysh.h"

char *home_path(char **my_env)
{
    int idx = 0;
    int d = 0;
    char *tmp = malloc(sizeof(char) * my_strlen(my_env[idx]));

    while (!(my_strcmp("HOME", my_env[idx]) == 1))
        idx++;

    tmp = malloc(sizeof(char) * my_strlen(my_env[idx]));

    for (int j = 5; my_env[idx][j] != '\0'; j++) {
        tmp[d] = my_env[idx][j];
        d++;
    }
    tmp[d] = '\0';
    return (tmp);
}

int search_chars(char *buff)
{
    for (int i = 0; buff[i]; i++)
        if (buff[i] == '<' ||
            buff[i] == '>' ||
            buff[i] == ';' ||
            buff[i] == '|')
            return (1);

    return (0);
}