/*
** EPITECH PROJECT, 2019
** strace
** File description:
** functions.c
*/

#include "strace.h"

int strace_p(char **av)
{
    int ret;
    int status;
    pid_t pid = atoi(av[2]);
    struct user_regs_struct regs;

    signal(SIGINT, stop_strace);
    ret = ptrace(PTRACE_ATTACH, pid, 0, 0);
    if (ret == -1){
        perror("strace: attach");
        return 84;
    }
    printf("strace: Process %d attached\n", pid);
    do_strace_p(pid, status, regs);

    return 0;
}

void do_strace_p(pid_t pid, int status, struct user_regs_struct regs)
{
    long long int syscallnb;

    while (waitpid(pid, &status, 0) && !WIFEXITED(status)) {
        ptrace(PTRACE_GETREGS, pid, NULL, &regs);
        if ((syscallnb = (int)regs.orig_rax) >= 0)
            print_regs(syscallnb, regs);
        ptrace(PTRACE_SINGLESTEP, pid, NULL, NULL);
    }
    stop_strace(pid);
}

void stop_strace(pid_t pid)
{
    ptrace(PTRACE_DETACH, pid, NULL, NULL);
    exit(0);
}


