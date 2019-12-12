/*
** EPITECH PROJECT, 2018
** cd_root
** File description:
** cd_root
*/

#include "mysh.h"

char **cd_root(char **env, char *value)
{
    char **value_env = env;
    char *tmp;
    int i = 0;

    while (!(my_strcmp("PWD", env[i]) == 1))
        i++;

    tmp = malloc(sizeof(char) * my_strlen(value) + 1);
    value_env[i] = malloc(sizeof(char) * my_strlen(value) + 5);

    tmp = my_strcat("PWD=", value);
    value_env[i] = tmp;
    return (value_env);
}