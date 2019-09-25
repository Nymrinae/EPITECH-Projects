/*
** EPITECH PROJECT, 2018
** my_print_comb
** File description:
** Displays in ascending order, all the numbers composed by three different digits
*/
#include <unistd.h>

void my_putchar(char c);

int print_number(char a, char b, char c)
{
    if (a == '7' && b == '8' && c == '9')
    {
	my_putchar(a);
	my_putchar(b);
	my_putchar(c);
    }
    else
    {
	my_putchar(a);
	my_putchar(b);
	my_putchar(c);
	my_putchar(',');
	my_putchar(' ');
    }    
    return (0);
}

void last_digit(char a, char b, char c)
{
    while (c <= '9') {
	print_number(a, b, c);
	c++;
    }
}

int my_print_comb(void)
{
    char a = '0';
    char b;
    char c;

    while (a <= '7' ) {
	b = a + 1;
	while (b <= '8') {
	    c = b + 1;
	    last_digit(a,b,c);
	    b++;
	}
	a++;
    }
    return (0);
}
