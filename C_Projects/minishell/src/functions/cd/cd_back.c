/*
** EPITECH PROJECT, 2018
** cd_back
** File description:
** cd_back
*/

#include "mysh.h"

char **cd_back(char **env, char *value)
{
    char **value_env;

    if (my_strcmp("..", value) == 1)
        value_env = cd_two_point(env, value);
    if (my_strcmp("/", value) == 1)
        value_env = cd_root(env, value);

    return (value_env);
}