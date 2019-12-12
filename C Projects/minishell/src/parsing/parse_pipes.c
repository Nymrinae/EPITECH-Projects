/*
** EPITECH PROJECT, 2018
** parse_pipes
** File description:
** parsing pipes
*/

#include "mysh.h"

int parse_arg_pipes_one(char *buffer, char *arg1[])
{
    int j = 0;
    int k = 0;
    int i = 0;
    char *tmp = malloc(sizeof(char *) * 1024);
    i = parse_space_and_tab(buffer, i);
    while (!(buffer[i] == '|')) {
        if (buffer[i] == ' ' || buffer[i] == 9) {
            tmp[k] = '\0';
            arg1[j] = tmp;
            j++;
            k = 0;
            tmp = malloc(sizeof(char *) * 1024);
            i = parse_space_and_tab(buffer, i);
        } else {
            tmp[k] = buffer[i];
            k++;
            i++;
        }
    }
    tmp[k] = '\0';
    arg1[j] = tmp;
    return (i+1);
}

int parse_arg_pipes_two(char *buffer, char *arg2[], int idx)
{
    int j = 0;
    int k = 0;
    char *tmp = malloc(sizeof(char *) * 1024);
    idx = parse_space_and_tab(buffer, idx);
    while (buffer[idx] != '\n') {
        if (buffer[idx] == ' ' || buffer[idx] == 9) {
            tmp[k] = '\0';
            arg2[j] = tmp;
            j++;
            k = 0;
            tmp = malloc(sizeof(char *) * 1024);
            idx = parse_space_and_tab(buffer, idx);
        }else {
            tmp[k] = buffer[idx];
            k++;
            idx++;
        }
    }
    tmp[k] = '\0';
    arg2[j] = tmp;
}
