/*
** EPITECH PROJECT, 2018
** test_path.c
** File description:
** exec_binary
*/

#include "mysh.h"

char *test_path(char *bin, char *pathname)
{
    char *path_bin[] = {"/bin/", "./local/bin/", "/usr/share/Modules/bin",
    "/usr/local/bin/", "/sbin/", "/usr/bin/",  "/usr/sbin/"};

    for (int i = 0; i < 6; i++) {
        bin = my_strcat(path_bin[i], pathname);
        if (access(bin, X_OK) == 0)
            return (bin);
        else {
            bin = malloc(sizeof(char) * (my_strlen(path_bin[i + 1])
            + my_strlen(pathname)) + 1);
        }
    }
    return (bin);
}