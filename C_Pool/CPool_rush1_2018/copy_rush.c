#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

int line(int x, int bool)
{
    my_putchar('o');
    for (int i = 0; i <= x - 2; i++) {
       my_putchar('-');
    }
    if (x != 1)
       my_putchar('o');
    my_putchar('\n');
}

int body(int x, int y)
{
    for (int i = 0; i < y - 2; i++) {
	my_putchar('|');
	for (int j = 0; j <= x - 2; j++) {
	    my_putchar(' ');
	}
	if (x != 1)
	    my_putchar('|');
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
	my_putchar('o');
	return ;
    }
    
    line(x, 0);
    body(x, y);
    if (y != 1)
	line(x, 1);
}


int main()
{
    rush(1, 4);
}
