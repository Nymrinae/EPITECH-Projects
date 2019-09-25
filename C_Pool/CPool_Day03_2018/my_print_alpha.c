/*
** EPITECH PROJECT, 2018
** my_print_alpha
** File description:
** Displays lowercase alphabet in ascending order
*/

#include <unistd.h>

void my_putchar(char c);

int my_print_alpha(void)
{
    char c = 'a';
    
    while (c <= 'z') {
      my_putchar(c);
      c++;
    }
    return (0);
}
