/*
** EPITECH PROJECT, 2018
** strcat
** File description:
** strcat
*/

#include "my.h"

char *my_strcat(char *dest, char const *src)
{
	int i = 0;
	int start = my_strlen(dest);

        for (; src[i] != '\0'; i++) {
		dest[start + i] = src[i];
	}
	dest[start + i] = '\0';
	return (dest);
}
