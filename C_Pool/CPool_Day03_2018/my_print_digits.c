/*
** EPITECH PROJECT, 2018
** my_print_digits
** File description:
** Displays in ascending order all digits on a single line
*/

#include <unistd.h>

void my_putchar(char c);

int my_print_digits(void)
{
    char c = 48;
    while (c <= 57) {
		my_putchar(c);
		c++;
    }
    return (0);
}
