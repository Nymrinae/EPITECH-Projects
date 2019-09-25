/*
** EPITECH PROJECT, 2018
** Rush 1
** File description:
** The Squares
*/

#include <unistd.h>

void my_putchar(char c);

void one_line(int x, int y, int bool)
{
    if (bool == 0) {
	for (int a = 0; a < x; a++) {
	    my_putchar('B');
	}
    }
    else
    {
	for (int b = 0; b < y; b++) {
	    my_putchar('B');
	    my_putchar('\n');
	}
    }
}

int line(int x, int bool)
{
    if (bool == 0) {
	my_putchar('A');
	for (int i = 0; i < x - 2; i++) {
	    my_putchar('B');
	}
	if (x != 1)
	    my_putchar('C');
	my_putchar('\n');
    }
    else
    {
	if (x != 1)
	    my_putchar('C');
	for (int i = 0; i < x - 2; i++) {
	    my_putchar('B');
	}
	my_putchar('A');
	my_putchar('\n');
    }
}

int body(int x, int y)
{
    for (int i = 0; i <  y - 2; i++) {
	my_putchar('B');
	for (int j = 0; j < x - 2; j++) {
	    my_putchar(' ');
	}
	if (x != 1)
	    my_putchar('B');
	my_putchar('\n');
    }
}

void rush(int x, int y)
{
    if (x <= 0 || y <= 0) {
	write(1, "Invalid size\n", 14);
	return ;	
    }
    if (x == 1 && y == 1) {
	my_putchar('B');
	return ;
    }
    if (x == 1 && y != 1) {
	one_line(x, y, 1);
	return ;
    }
    else if (x != 1 && y == 1) {
	one_line(x, y, 0);
	return ;
    }
    if (x != 1)
	line(x, 0);
    body(x, y);    
    if (y != 1)
	line(x, 1);
}
