/*
** EPITECH PROJECT, 2018
** cd_commands
** File description:
** cd_commands
*/

#include "mysh.h"

int cd_command(char *pathname, char **my_env)
{
    struct stat file;
    int error;
    char *home = home_path(my_env);

    if (my_strcmp("~", pathname) == 0) {
        stat(pathname, &file);
        error = error_repo(file, pathname);

        if (error == 0)
            chdir(pathname);
    }
    else if (my_strcmp("~", pathname) == 1)
        chdir(home);
    return (error);
}
