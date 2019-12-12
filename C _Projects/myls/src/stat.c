/*
** EPITECH PROJECT, 2018
** stat.c
** File description:
** stat
*/

#include "../include/my_ls.h"

int get_size(char **files, int nb_files, char *path)
{
    struct stat sf;
    int total = 0;

    for (int i; i < nb_files; i++) {
        stat(files[i], &sf);
        total += sf.st_blocks;
    }
    total /= 2;

    return (total);
}

void parse_time(char *str)
{
    int str_size = my_strlen(str);
    char *substr = malloc(sizeof(char *) * str_size);

    my_strncpy(substr, str + 4, 12);
    my_putchar(32);
    my_putstr(substr);
    free(substr);
}

int get_mtime(char *file)
{
    struct stat sf;
    stat(file, &sf);

    return (sf.st_mtime);
}

void dir(char *dir, struct opt options)
{
    if (options.opt_l == 1)
        print_stat(dir);
    my_putchar(32);
    my_putstr(dir);
    my_putchar(10);
}

int dir_exist(char *directory)
{
    DIR *dir;

    if ((dir = opendir(directory)) == NULL) {
        my_putstr("my_ls: cannot access '");
        my_putstr(directory);
        my_putstr("': No such file or directory\n");
        return (84);
    } else
        return (0);
}