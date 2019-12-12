/*
** EPITECH PROJECT, 2018
** next_execute_cd
** File description:
** next_execute_cd
*/

#include "mysh.h"

char **next_execute_cd(char *path, char *arg[], char **my_env, int size)
{
    int error = 0;

    if (my_strcmp("..", path) == 1) {
        my_env = my_unsetenv(my_env, arg[1], false);
        cd_command(path, my_env);
    } else if (my_strcmp("/", path) == 1) {
        error = cd_command(path, my_env);
        if (error == 0) {
            my_env = my_unsetenv(my_env, arg[1], false);
            cd_command(path, my_env);
        }
    } else if (my_strcmp("~", path) == 1 || size == 3) {
        cd_command("~", my_env);
        my_env = my_unsetenv(my_env, path, true);
    } else {
        error = cd_command(path, my_env);
        if (error == 0)
            my_env = my_setenv(my_env, arg[1]);
    }
    return (my_env);
}