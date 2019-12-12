/*
** EPITECH PROJECT, 2018
** parse_separator
** File description:
** parsing separators
*/

#include "mysh.h"

void parsing_semicolons(char **env, char *buffer, char *arg[])
{
    int i = 1;
    int idx = 0;
    int l = 0;
    int ac = count_arg(buffer);
    int count = 1;
    char *path;
    char *my_arg[1024];
    int size = my_strlen(buffer);

    while (i <= ac) {
        parse_arg_semicolons(buffer, arg);
        i++;
    }
    for (int k = 0; k < ac; k++) {
        path = malloc(1024 * sizeof(char));
        parse_pathname(arg[k], path);
        execute_binary(path, arg[k], my_arg, env);
        free_arg(my_arg);
        free(path);
    }
}

int parse_semicolons_and_tab(char *buffer, int idx)
{
    while ((buffer[idx] == ';'))
        idx++;
    return (idx);
}

void parse_arg_semicolons(char *s1, char *s2[])
{
    int j = 0;
    int k = 0;
    int i = 0;
    char *tmp = malloc(sizeof(char *) * 1024);
    i = parse_space_and_tab(s1, i);
    while (s1[i] != '\n') {
            if (s1[i] == ';' || s1[i] == 9) {
            tmp[k] = '\0';
            s2[j] = tmp;
            j++;
            k = 0;
            tmp = malloc(sizeof(char *) * 1024);
            i = parse_semicolons_and_tab(s1, i);
            i = parse_space_and_tab(s1, i);
        } else {
            tmp[k] = s1[i];
            k++;
            i++;
        }
    }
    tmp[k] = '\0';
    s2[j] = tmp;
}
