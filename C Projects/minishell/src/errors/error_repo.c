/*
** EPITECH PROJECT, 2018
** error_repo
** File description:
** error dir
*/

#include "mysh.h"

int error_repo(struct stat file, char *path)
{
    DIR *list = NULL;
    struct dirent *directory;

    switch(file.st_mode & __S_IFMT) {
        case (__S_IFREG):
            my_putstr(path);
            write(2, NOT_DIR, my_strlen(NOT_DIR));
            return (84);
            break;
        case (!__S_IFDIR):
            list = opendir(path);
            if (list == NULL) {
                my_putstr(path);
                write(2, NOT_FILE_OR_DIR, my_strlen(NOT_FILE_OR_DIR));
                return (84);
                break;
            }
        default:
            return (0);
    }
}