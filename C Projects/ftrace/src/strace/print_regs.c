/*
** EPITECH PROJECT, 2019
** strace
** File description:
** print_regs.c
*/

#include "strace.h"

void print_regs(long long int syscallnb, struct user_regs_struct regs)
{
    print_name(syscallnb, regs);
    print_params(syscallnb, regs);
    print_retval(regs);
}

void print_name(long long int syscallnb, struct user_regs_struct regs)
{
    printf("%s(", tab_syscalls[syscallnb].name);
}

void print_params(long long int syscallnb, struct user_regs_struct regs)
{
    char *a = "0x%lx, 0%lx, 0%lx, 0%lx";
    char *b = "0x%lx, 0%lx, 0%lx, 0%lx, 0%lx";
    char *c = "0x%lx, 0%lx, 0%lx, 0%lx, 0%lx, 0%lx";
    switch(tab_syscalls[syscallnb].nb_params){
        case 1: printf("0x%lx", regs.rdi); break;
        case 2: printf("0x%lx, 0x%lx", regs.rdi, regs.rsi); break;
        case 3:
            printf("0x%lx, 0%lx, 0%lx", regs.rdi, regs.rsi, regs.rdx);
        break;
        case 4:
            printf(a, regs.rdi, regs.rsi, regs.rdx, regs.r10); break;
        case 5:
            printf(b, regs.rdi, regs.rsi, regs.rdx, regs.r10, regs.r8);
            break;
        case 6:
            printf(c, regs.rdi, regs.rsi, regs.rdx,
                regs.r10, regs.r8, regs.r9);
            break;
        default: return;
    }
}

void print_retval(struct user_regs_struct regs)
{
    printf(") = 0x%lx\n", regs.rax);
}