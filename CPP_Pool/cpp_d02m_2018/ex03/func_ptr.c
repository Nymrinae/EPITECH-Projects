/*
** EPITECH PROJECT, 2018
** func_ptr.c
** File description:
** Exercise 3 - Func Ptr - Function Pointers
*/

#include "func_ptr.h"

void do_action(action_t action, const char *str)
{
    void (*actions[])(const char *) = {
        print_normal,
        print_reverse,
        print_upper,
        print_42
    };

    (*actions[action])(str);
}

void print_normal(const char *str)
{
    printf("%s\n", str);
}

void print_reverse(const char *str)
{
    for (int i = strlen(str) - 1; str[i]; i--)
        printf("%c", str[i]);
    printf("\n");
}

void print_upper(const char *str)
{
    for (int i = 0; str[i]; i++)
        printf("%c", toupper(str[i]));
    printf("\n");
}

void print_42(const char *str)
{
    if (str)
        printf("42\n");
}