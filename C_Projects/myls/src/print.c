/*
** EPITECH PROJECT, 2018
** print.c
** File description:
** print.c
*/

#include "../include/my_ls.h"

int my_ls_print(char **index, char *path, int nb_files, struct opt options)
{
    int i = 0;
    int opt_has_l = options.opt_l;
    char **files = fill_array_name(path, nb_files);

    sort_tab(files, nb_files, options);
    if (options.opt_t == 1) {
        sort_time(files, nb_files, options);
        sort_time(index, nb_files, options);
    }
    if (opt_has_l) {
        my_putstr("total ");
        my_put_nbr(get_size(files, nb_files, path));
        my_putchar('\n');
    }
    while (i < nb_files) {
        if (opt_has_l)
            print_stat(files[i]);
        print_color(index[i]);
        if (opt_has_l)
            my_putchar('\n');
        ++i;
    }
    if (!opt_has_l)
        my_putchar('\n');
}

int print_stat(char *filename)
{
    struct stat sf;
    struct passwd *pwuid;
    struct group *grp;

    if (stat(filename, &sf) == -1) {
        perror("stat");
        return (84);
    }
    else {
        print_file_perms(&sf);
        if ((pwuid = getpwuid(sf.st_uid)) == NULL) {
            perror("getpwuid");
            return (84);
        }
        else {
            my_put_nbr(sf.st_nlink);
            my_putchar(32);
            my_putstr(my_strcat(pwuid->pw_name, " "));
            grp = getgrgid(sf.st_gid);
            my_putstr(my_strcat(grp->gr_name, " "));
            my_put_nbr(sf.st_size);
            parse_time(ctime(&sf.st_mtime));
        }
    }
    return (0);
}

void print_file_perms(struct stat *sf)
{
    switch(sf->st_mode & __S_IFMT) {
        case (__S_IFDIR): my_putchar('d'); break;
        case (__S_IFCHR): my_putchar('c'); break;
        case (__S_IFBLK): my_putchar('c'); break;
        case (__S_IFIFO): my_putchar('1'); break;
        default: my_putstr("-");
    }

    my_putchar((sf->st_mode & S_IRUSR) ? 'r' : '-');
    my_putchar((sf->st_mode & S_IWUSR) ? 'w' : '-');
    my_putchar((sf->st_mode & S_IXUSR) ? 'x' : '-');
    my_putchar((sf->st_mode & S_IRGRP) ? 'r' : '-');
    my_putchar((sf->st_mode & S_IWGRP) ? 'w' : '-');
    my_putchar((sf->st_mode & S_IXGRP) ? 'x' : '-');
    my_putchar((sf->st_mode & S_IROTH) ? 'r' : '-');
    my_putchar((sf->st_mode & S_IWOTH) ? 'w' : '-');
    my_putchar((sf->st_mode & S_IXOTH) ? 'x' : '-');
    my_putstr(" ");
}

void parse_filename(char *av)
{
    int index = 0;
    int slash = 0;

    for (int i = 0; av[i]; i++) {
        if (av[i] == '/') {
            index = i;
            slash++;
        }
    }
    my_putchar(' ');
    for (int i = (slash == 0) ? (index) : (index + 1); av[i]; i++)
        my_putchar(av[i]);
    my_putchar('\n');
}

void print_dir_content(char *dir)
{
    DIR *list;
    struct dirent *file;

    list = opendir(dir);
    while (file = readdir(list)) {
        if (!(file->d_name[0] == '.'))
            my_putstr(file->d_name);
        my_putchar(' ');
    }
    my_putchar('\n');
    closedir(list);
}