/*
** EPITECH PROJECT, 2018
** unsetenv
** File description:
** unsetenv related functions
*/

#include "mysh.h"

char **my_unsetenv(char **env, char *value, bool_t num)
{
    return (num ? cd_home(env) : cd_back(env, value));
}