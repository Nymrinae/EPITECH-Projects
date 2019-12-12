/*
** EPITECH PROJECT, 2018
** parse_cd
** File description:
** parse_cd
*/

#include "mysh.h"

void parse_path_cd(char *buffer, char *path)
{
    int i = 0;
    int j = 0;

    while (!(buffer[i] == ' ' || buffer[i] == 9))
        i++;

    i = parse_space_and_tab(buffer, i);

    while (buffer[i] != '\n') {
        path[j] = buffer[i];
        i++;
        j++;
    }

    path[j] = '\0';
}

int parse_space_and_tab(char *buffer, int idx)
{
    while ((buffer[idx] == ' ' || buffer[idx] == 9))
        idx++;
    return (idx);
}

void parse_arg(char *s1, char *s2[])
{
    int j = 0;
    int k = 0;
    int i = 0;
    char *tmp = malloc(sizeof(char *) * 1024);
    i = parse_space_and_tab(s1, i);
    while (s1[i] != '\n') {
        if (s1[i] == ' ' || s1[i] == 9) {
            tmp[k] = '\0';
            s2[j] = tmp;
            j++;
            k = 0;
            tmp = malloc(sizeof(char *) * 1024);
            i = parse_space_and_tab(s1, i);
        } else {
            tmp[k] = s1[i];
            k++;
            i++;
        }
    }
    tmp[k] = '\0';
    s2[j] = tmp;
    delete_space_and_tab(s2);
}

void parse_two_point(char *value, char *pwd, int size_pwd)
{
    int i = 0;

    while (value[i] != '\0') {
        if (value[i] == '.' && value[i+1] == '.') {
            i += 2;
            clean_pwd(pwd, size_pwd);
            size_pwd = my_strlen(pwd) + 1;
        } else {
            pwd[size_pwd] = value[i];
            i++;
            size_pwd++;
        }
    }
    pwd[size_pwd] = '\0';
}
