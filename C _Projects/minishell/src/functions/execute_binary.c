/*
** EPITECH PROJECT, 2018
** execute_binary
** File description:
** execute_binary
*/

#include "mysh.h"

int execute_binary(char *pathname, char *buffer, char *arg[], char **my_env)
{
    char *bin = malloc(sizeof(char) * (6 + my_strlen(pathname)) + 1);
    pid_t pid;

    bin = test_path(bin, pathname);
    parse_arg(buffer, arg);
    if (access(bin, X_OK) == 0) {
        pid = fork();
        if (pid == 0)
            execve(bin, arg, my_env);
        else
            wait(NULL);
    }
    else {
        buffer[my_strlen(buffer) - 1] = '\0';
        my_putstr(buffer);
        write(2, CMD_NOT_FOUND, my_strlen(CMD_NOT_FOUND));
    }
}