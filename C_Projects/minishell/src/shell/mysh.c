/*
** EPITECH PROJECT, 2018
** mysh
** File description:
** mysh main function
*/

#include "mysh.h"

int mysh(int ac, char **av, char **env)
{
    char **my_env = env;
    int status = 0;
    char buffer[30000];
    char *arg[1024];
    int size;

    status = loop(my_env, buffer, arg, size);
    return (status);
}

int loop(char **my_env, char *buffer, char *arg[], int size)
{
    int status = 0;

    while (status == 0)
        if (next_loop(my_env, buffer, arg, size) == 0)
            return (0);

    return (status);
}

int next_loop(char **my_env, char *buffer, char *arg[], int size)
{
    char *path = malloc(sizeof(char) * 30000);
    int file;

    my_putstr(">");
    size = read(file, buffer, 29999);
    if (size == 0) {
        my_putchar('\n');
        return (0);
    }
    buffer[size] = '\0';
    path = parse_pathname(buffer, path);
    if (search_chars(buffer)) return (84);
    else if (my_strcmp(path, "cd") == 1)
        my_env = execute_cd(buffer, arg, my_env, size);
    else if ((my_strcmp("exit", buffer) == 1) && (size == 5)) return (0);
    else execute_binary(path, buffer, arg, my_env);
    free_arg(arg);
    return (1);
}