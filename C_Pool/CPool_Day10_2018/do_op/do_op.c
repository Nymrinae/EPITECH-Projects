/*
** EPITECH PROJECT, 2018
** do_op
** File description:
** Day 10 Task 02
*/

#include "../include/my.h"
#include <stdio.h>

int operation(int a, char op, int b)
{
    switch(op) {
        case '+':
            return (a + b);
        case '-':
            return (a - b);
        case '*':
            return (a * b);
        case '/':
            if (b != 0)
                return (a / b);
            else
                my_putstr("Stop: division by zero");
            break;
        case '%':
            if (b != 0)
                return (a % b);
            else
                my_putstr("Stop : modulo by zero");
            break;
        default:
            return (0);
    }
}

int main(int argc, char **argv)
{
    char op = argv[2][0];
    int a = my_getnbr(argv[1]);
    int b = my_getnbr(argv[3]);
    int nb = operation(a, op, b);

    if (argc != 4)
        return (84);
    
    my_put_nbr(nb);
}
