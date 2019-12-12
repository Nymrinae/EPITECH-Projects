/*
** EPITECH PROJECT, 2019
** strace
** File description:
** strace.c
*/

#include "strace.h"

int strace(char **av)
{
    int status;
    pid_t pid;
    char *args[] = {av[1], av[2], NULL};
    struct user_regs_struct regs;

    pid = fork();
    if (pid == -1)
        perror("fork : ");
    if (pid == 0)
        err_pid(av, args);
    do_strace(av, pid, status, regs);

    return 0;
}

void do_strace(char **av, pid_t pid, int status, struct user_regs_struct regs)
{
    long long int syscallnb;

    while (waitpid(pid, &status, 0) && !WIFEXITED(status)) {
        ptrace(PTRACE_GETREGS, pid, NULL, &regs);
        if ((syscallnb = (int)regs.orig_rax) >= 0) {
            (!strcmp(av[1], "-s"))  ? print_regs_s(syscallnb, regs)
                                    : print_regs(syscallnb, regs);
        }
        ptrace(PTRACE_SINGLESTEP, pid, NULL, NULL);
    }
}