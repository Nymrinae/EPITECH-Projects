/*
** EPITECH PROJECT, 2018
** mysh.h
** File description:
** mysh functions prototypes
*/

#ifndef _MY_SH_H_
#define _MY_SH_H_

// booltype
typedef enum {
    false,
    true
} bool_t;

//headers
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <errno.h>
#include "my.h"

//strings
#define NOT_DIR ": Not a directory.\n"
#define NOT_FILE_OR_DIR ": No such file or a directory.\n"
#define CMD_NOT_FOUND ": Command not found.\n"

//src/errors
int error_repo(struct stat file, char *path);

//src/functions
int execute_binary(char *pathname, char *buffer, char *arg[], char **my_env);

char *home_path(char **my_env);
int search_chars(char *buff);

int count_line(char **env);
int count_arg(char *str);
void free_arg(char *arg[]);
void clean_pwd(char *pwd, int size_pwd);

//src/functions/cd
int cd(char *buffer, int size, char *path, char *arg[]);
char **cd_home(char **env);
char **cd_back(char **env, char *value);
char **cd_root(char **env, char *value);
int cd_command(char *pathname, char **my_env);
char **cd_two_point(char **env, char *value);
char **next_execute_cd(char *path, char *arg[], char **my_env, int size);
char **execute_cd(char *buffer, char *arg[], char **my_env, int size);

//src/functions/path
char *test_path(char *bin, char *pathname);

//functions/setenv
char **my_setenv(char **env, char *value);
int check_line_setenv(char *name, char **env);

char **my_unsetenv(char **env, char *value, bool_t num);

//src/mysh
int mysh(int ac, char **av, char **env);
int loop(char **my_env, char *buffer, char *arg[], int size);
int next_loop(char **my_env, char *buffer, char *arg[], int size);

//src/parsing
void parse_hostname(char *hostname);
void parse_username(char *username);
void parse_file_name(char *str);
char *parse_pathname(char *s1, char *s2);
char *next_parse_pathname(char *tmp, char *s2, int k, int count);

void parse_arg(char *s1, char *s2[]);
void parse_path_cd(char *buffer, char *path);
int parse_space_and_tab(char *buffer, int idx);
void parse_two_point(char *value, char *pwd, int size_pwd);

int parse_arg_pipes_two(char *buffer, char *arg2[], int idx);
int parse_arg_pipes_one(char *buffer, char *arg1[]);

void parsing_semicolons(char **env, char *buffer, char *arg[]);
int parse_semicolons_and_tab(char *buffer, int idx);
void parse_arg_semicolons(char *s1, char *s2[]);

//redirection
int search_pipes(char *buffer);
int pipes(char *buffer, char **env);
void delete_space_and_tab(char *arg[]);

#endif