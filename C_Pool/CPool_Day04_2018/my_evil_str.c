/*
** EPITECH PROJECT, 2018
** my_evil_str.c
** File description:
** Swaps each of the string's characters, two by two
*/

#include <unistd.h>

int my_strlen(char *str);

char *my_evil_str(char *str)
{
    char *string = str;    
    int i = 0;
    int j = my_strlen(string) - 1;

    while (str[i]) {
	string[j] = str[i];
	i++;
	j--;
    }
    return (string);
}
