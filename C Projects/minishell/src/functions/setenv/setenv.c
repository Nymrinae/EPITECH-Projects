/*
** EPITECH PROJECT, 2018
** setenv
** File description:
** setenv related
*/

#include "mysh.h"

char **my_setenv(char **env, char *value)
{
    char **value_env;
    int a = check_line_setenv(value, env);

    if (value != NULL) {
        value_env = malloc(count_line(env) * sizeof(*value_env) + 2);
        for (int i = 0; env[i]; i++) {
            value_env[i] = malloc((my_strlen(env[i]) + 1) *
            sizeof(**value_env));
            my_strcpy(value_env[i], env[i]);
        }
        if (a) {
            value_env[a] = my_strcat(value_env[a], "/");
            value_env[a] = my_strcat(value_env[a], value);
        } else {
            value_env[a] = malloc((my_strlen(value) + 1) * sizeof(**value_env));
            value_env[a] = my_strcpy(value_env[a], value);
        }
        return (value_env);
    }
}

int check_line_setenv(char *name, char **env)
{
    int i = 0;

    while (env[i] != NULL) {
        if (my_strcmp("PWD", env[i]) == 1) {
            return (i);
        }
        i++;
    }
}