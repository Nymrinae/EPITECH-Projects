/*
** EPITECH PROJECT, 2018
** my_putstr
** File description:
** Displays one by one the characters of a string
*/

#include <unistd.h>

void my_putchar(char c);

int my_putstr(char const *str)
{
    int i = 0;
    
    while (str[i]) {
	    my_putchar(str[i]);
   	    i++;
    }
    return (0);
}
