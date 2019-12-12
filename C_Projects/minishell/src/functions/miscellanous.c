/*
** EPITECH PROJECT, 2018
** miscellanous
** File description:
** others functions
*/

#include "mysh.h"

int count_line(char **env)
{
    int i = 0;

    while (env[i] != NULL)
        i++;
    return (i);
}

int count_arg(char *str)
{
    int count = 1;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ';')
            count++;
    }

    return (count);
}

void free_arg(char *arg[])
{
    for (int i = 0; i < 1023; i++)
        arg[i] = NULL;
}

void clean_pwd(char *pwd, int size_pwd)
{
    pwd[size_pwd - 1] = '\0';

    while (pwd[size_pwd] != '/') {
        pwd[size_pwd] = '\0';
        size_pwd--;
    }
    if (size_pwd != 4)
        pwd[size_pwd] = '\0';
}

void delete_space_and_tab(char *arg[])
{
    int i = 0;

    while (arg[i] != NULL)
        i++;

    if (arg[i - 1][0] == '\0')
        arg[i - 1] = NULL;
}
