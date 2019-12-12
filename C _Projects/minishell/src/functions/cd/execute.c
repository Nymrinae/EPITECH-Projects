/*
** EPITECH PROJECT, 2018
** execute_cd
** File description:
** execute_cd
*/

#include "mysh.h"

char **execute_cd(char *buffer, char *arg[], char **my_env, int size)
{
    char *path = malloc(sizeof(char) * my_strlen(buffer));

    if (buffer[0] == '\n')
        return (my_env);
    if (size > 3) {
        parse_path_cd(buffer, path);
        parse_arg(buffer, arg);
    }
    my_env = next_execute_cd(path, arg, my_env, size);
    return (my_env);
}