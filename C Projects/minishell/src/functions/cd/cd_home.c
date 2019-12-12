/*
** EPITECH PROJECT, 2018
** cd_home
** File description:
** cd_home
*/

#include "mysh.h"

char **cd_home(char **env)
{
    char **value_env = env;
    int i = 0;
    int k = 0;
    char *tmp;
    char *home = home_path(env);

    while (!(my_strcmp("HOME", env[i]) == 1))
        i++;
    while (!(my_strcmp("PWD", env[k]) == 1))
        k++;

    tmp = malloc(sizeof(char) * my_strlen(env[i]) + 1);
    value_env[k] = malloc(sizeof(char) * my_strlen(env[i]) + 1);

    tmp = my_strcat("PWD=", home);
    value_env[k] = tmp;
    return (value_env);
}
