/*
** EPITECH PROJECT, 2018
** functions.c
** File description:
** functions used for my_ls
*/

#include "../include/my_ls.h"

void init_options(struct opt *opt)
{
    opt->opt_l = 0;
    opt->opt_d = 0;
    opt->opt_r = 0;
    opt->opt_R = 0;
    opt->opt_t = 0;
}

char *getpath(char *dirname, char *path)
{
    char *dirpath = NULL;
    int path_len = my_strlen(path);
    int size = path_len + my_strlen(dirname);
    int index = 0;

    dirpath = malloc(size * sizeof(char *));
    my_strcat(dirpath, path);
    if (dirpath[path_len - 1] != '/')
        dirpath[path_len] = '/';
    path_len++;
    my_strcat(dirpath, dirname);

    for (int i = 0; dirpath[i]; i++) {
        if (dirpath[i] == '/')
            index++;
    }
    return (dirpath);
}

char *my_strdup(char const *src)
{
    int src_len = my_strlen(src) + 1;
    char *newstr = malloc(src_len * sizeof(char));

    newstr = my_strcpy(newstr, src);
    newstr[src_len - 1] = '\0';
    return (newstr);
}

int manage_errors(int ac, char **av)
{
    my_putstr("ls: cannot access '");
    my_putstr(av[ac - 1]);
    my_putstr("': No such file or directory\n");
   
    return (0);
}
