/*
** EPITECH PROJECT, 2018
** strncat
** File description:
** strncat
*/

#include "my.h"

char *my_strncat(char *dest, char const *src, int nb)
{
	int i = 0;
	int start = my_strlen(dest);

        for (; nb - 1 > i && src[i] != '\0'; i++) {
		dest[start + i] = src[i];
	}
	dest[start + i] = '\0';
	return (dest);
}
