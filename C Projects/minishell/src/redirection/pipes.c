/*
** EPITECH PROJECT, 2018
** mysh
** File description:
** mysh main function
*/

#include "mysh.h"

int search_pipes(char *buffer)
{
    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == '|')
            return (1);
    }
    return (0);
}

int pipes(char *buffer, char **env)
{
    int pfd[2];
    int pid;
    int pid2;
    char *bin1 = malloc(sizeof(char) * (6 + my_strlen(buffer)) + 1);
    char *bin2 = malloc(sizeof(char) * (6 + my_strlen(buffer)) + 1);
    char *arg1[1024];
    char *arg2[1024];
    int idx = parse_arg_pipes_one(buffer, arg1);

    parse_arg_pipes_two(buffer, arg2, idx);
    bin1 = test_path(bin1, arg1[0]);
    bin2 = test_path(bin2, arg2[0]);
    delete_space_and_tab(arg1);
    delete_space_and_tab(arg2);

    if (pipe(pfd) == -1) {
        my_putstr("pipe failed\n");
        return (84);
    }if ((pid = fork()) < 0) {
        my_putstr("fork failed\n");
        return (84);
    }if (pid == 0) {
        close(pfd[1]);
        dup2(pfd[0], 0);
        close(pfd[0]);
        execve(bin2, arg2, env);
        return (84);
    }else {
        close(pfd[0]);
        dup2(pfd[1], 1);
        close(pfd[1]);
        execve(bin1, arg1, env);
        return (84);
    }
    return (0);
}
