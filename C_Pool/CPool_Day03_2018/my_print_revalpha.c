/*
** EPITECH PROJECT, 2018
** my_print_revalpha
** File description:
** Displays the lowercase alphabet in descending order
*/

#include <unistd.h>

void my_putchar(char c);

int my_print_revalpha(void)
{
   char c = 'z';
   while (c >= 'a') {
     my_putchar(c);
     c--;
   }
   return (0);
}
