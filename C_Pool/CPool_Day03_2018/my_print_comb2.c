/*
** EPITECH PROJECT, 2018
** my_print_comb2
** File description:
** ??? 
*/

#include <unistd.h>

void my_putchar(char c);

int display_digits(int x)
{
    char first = (x / 10) + 48;
    char second = (x % 10) + 48;
    
    my_putchar(first);
    my_putchar(second);
}

int my_print_comb2(void)
{
    int a = 0;
    int b = 1;

    while (a < 99) {
	b = a + 1;
	while (b < 100) {
	    display_digits(a);
	    my_putchar(' ');
	    display_digits(b);
	    if(a != 98 || b != 99) {
		my_putchar(',');
		my_putchar(' ');
	    }
	    b++;
	}
	a++;
    }
}
