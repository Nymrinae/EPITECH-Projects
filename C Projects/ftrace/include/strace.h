/*
** EPITECH PROJECT, 2019
** strace.h
** File description:
** strace header
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <sys/reg.h>
#include <syscall.h>
#include <sys/wait.h>
#include <sys/user.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/ptrace.h>
#include <sys/resource.h>

//#include "types.h"
#include "syscalls.h"

// errors
int     usage(int);
void    args_err(char);
int     no_args(int ac);
int     err_pid(char **, char *args[]);

// global functions
int     run_strace(char **av);

// strace wo/ options
int     strace(char **av);
void     do_strace(char **av, pid_t, int, struct user_regs_struct);

void    print_retval(struct user_regs_struct regs);
void    print_name(long long int, struct user_regs_struct regs);
void    print_params(long long int, struct user_regs_struct regs);
void    print_regs(long long int, struct user_regs_struct regs);

// strace -p
int     strace_p(char **);
void    stop_strace(pid_t pid);
void    do_strace_p(pid_t pid, int status, struct user_regs_struct regs);

// strace -s
void    print_retval_s(long long int, struct user_regs_struct regs);
void    print_type(long long int, struct user_regs_struct regs);
void    print_regs_s(long long int syscallnb, struct user_regs_struct regs);
