/*
** EPITECH PROJECT, 2018
** my_isneg
** File description:
** Displays either N or P depending of the integer passed as parameter
*/

#include <unistd.h>

void my_putchar(char c);

int my_isneg(int n)
{
    (n >= 0) ? my_putchar('P') : my_putchar('N');
    return (0);
}
