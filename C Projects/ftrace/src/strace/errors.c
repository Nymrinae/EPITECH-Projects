/*
** EPITECH PROJECT, 2019
** strace
** File description:
** errors.c
*/

#include "strace.h"

int usage(int ret)
{
    printf("USAGE: ./strace [-s] [-p <pid>|<command>\n");

    return ret;
}

void args_err(char c)
{
    char value[20];
    char arg[255] = "strace: option requires an argument";
    char try[50] = "Try 'strace --help' for more information.\n";

    snprintf(value, strlen(arg), " -- '%c'\n", c);
    strcat(arg, value);
    strcat(arg, try);
    write(2, arg, strlen(arg));
}

int no_args(int ac)
{
    char err[100] = "strace: must have PROG [ARGS] or -p PID\n";
    char try[50] = "Try 'strace --help' for more information.\n";

    strcat(err, try);
    if (ac < 2) {
        write(2, err, strlen(err));
        return 1;
    }
    return 0;
}

int err_pid(char **av, char *args[])
{
    int ret;

    ptrace(PTRACE_TRACEME, 0, 0, 0);
    if ((!strcmp(av[1], "-s") || !strcmp(av[1], "-p")) && !av[2]) {
        args_err(av[1][1]);
        exit(84);
    }
    ret = execvp((!strcmp(av[1], "-s")) ? av[2] : av[1], args);
    if (ret == -1) {
        args_err('s');
        exit(84);
    }
}