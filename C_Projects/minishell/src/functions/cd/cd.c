/*
** EPITECH PROJECT, 2018
** cd
** File description:
** cd
*/

#include "mysh.h"

int cd(char *buffer, int size, char *path, char *arg[])
{
    int status = 0;

    if ((my_strcmp("cd", buffer) == 1) && size == 3)
        return (1);
    else {
        parse_path_cd(buffer, path);
        parse_arg(buffer, arg);
    }
    return (0);
}
