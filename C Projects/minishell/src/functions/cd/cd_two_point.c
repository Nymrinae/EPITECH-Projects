/*
** EPITECH PROJECT, 2018
** cd ..
** File description:
** cd ..
*/

#include "mysh.h"

char **cd_two_point(char **env, char *value)
{
    char **value_env = env;
    int i = 0;
    int size;

    while (!(my_strcmp("PWD", env[i]) == 1))
        i++;

    size = my_strlen(env[i]);
    parse_two_point(value, value_env[i], size);
    return (value_env);
}