/*
** EPITECH PROJECT, 2018
** arrays.c
** File description:
** Allocates and fill dynamic arrays
*/

#include "../include/my_ls.h"

char **fill_array_name(char *path, int nb_files)
{
    DIR *dir;
    struct dirent *directory;
    int i = 0;
    char **tab = NULL;

    tab = malloc(nb_files * sizeof(char *));
    if ((dir = opendir(path)) == NULL)
        perror("my_ls");
    while ((directory = readdir(dir)) != NULL) {
        if (directory->d_name[0] != '.') {
            tab[i] = my_strdup(directory->d_name);
            i++;
        }
    }
    closedir(dir);
    return (tab);
}

char **fill_array_path(char *path, int nb_files)
{
    DIR *dir;
    struct dirent *directory;
    int i = 0;
    char **tab = NULL;

    tab = malloc(nb_files * sizeof(char *));
    if ((dir = opendir(path)) == NULL)
        perror("my_ls");
    while ((directory = readdir(dir)) != NULL) {
        if (directory->d_name[0] != '.') {
            tab[i] = getpath(directory->d_name, path);
            i++;
        }
    }
    closedir(dir);
    return (tab);
}