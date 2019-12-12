/*
** EPITECH PROJECT, 2018
** my_ls.h
** File description:
** header file my_ls
*/

#ifndef _MY_LS_H_
#define _MY_LS_H_

#include "my.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/sysmacros.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdarg.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <dirent.h>
#include <unistd.h>

struct opt {
    int opt_l;
    int opt_R;
    int opt_d;
    int opt_r;
    int opt_t;
};

int my_ls(int , char **, struct opt);
int my_ls_no_arg(char **, struct opt);

void parse_filename(char *);
void print_name(int, int, char *);
void parse_time(char *);
int get_size(char **path_of_files, int nb_files, char path[]);
int get_mtime(char *file);

int count_no_opt(char **);
int count_files(char *);

char **fill_array_name(char *, int);
char **fill_array_path(char *, int);
void sort_tab(char **, int n, struct opt);
void sort_time(char **tab, int n, struct opt options);
char *getpath(char *dirname, char *path);

void init_options(struct opt *);
void get_option(char **, struct opt *, int , int );
int *args_parser(char **, struct opt *, int);
void dir(char *, struct opt);
int dir_exist(char *dir);

void print_name(int, int, char *);
void print_dir_content(char *);
void print_color(char *);
int print_stat(char *);
void print_file_perms(struct stat *status);
int my_ls_print(char **index, char *path, int nb_files, struct opt options);

int manage_errors(int ac, char **av);

#endif /* _MY_LS_ */