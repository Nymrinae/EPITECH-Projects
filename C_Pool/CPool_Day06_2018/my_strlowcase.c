/*
** EPITECH PROJECT, 2018
** my_strlowercase
** File description:
** Puts every letter of every word in it in lowercase
*/

#include <stdio.h>

char *my_strlowcase(char *str)
{
    int i = 0;
    char *newstr;

    newstr = str;
    while (str[i]) {
	if (str[i] >= 'A' && str[i] <= 'Z')
	    str[i] = str[i] + 32;
	i++;
    }

    return (str);
}

int main(void)
{
    char *test;
    test = my_strlowcase("BonJoUr tOut LE moNdE");
    printf("%s", test);
}
