/*
** EPITECH PROJECT, 2019
** strace
** File description:
** print_regs_s.c
*/

#include "strace.h"

void print_regs_s(long long int syscallnb, struct user_regs_struct regs)
{
    print_name(syscallnb, regs);
    print_type(syscallnb, regs);
    print_retval_s(syscallnb, regs);
}

void print_type(long long int syscallnb , struct user_regs_struct regs)
{
    int nb_params = 0;
    char *type_params;

    for (int i = 0; i < tab_syscalls[syscallnb].nb_params; i++){
        nb_params = tab_syscalls[syscallnb].nb_params;
        type_params = tab_syscalls[syscallnb].params[i];
        printf((nb_params == i + 1) ? "%s" : "%s, ", type_params);
    }
}

void print_retval_s(long long int syscallnb, struct user_regs_struct regs)
{
    printf(") = %s\n", tab_syscalls[syscallnb].ret_type);
}

