/*
** EPITECH PROJECT, 2018
** my_strncmp
** File description:
** Reproduce strncmp function
*/

#include <stdio.h>

int my_strncmp(char *s1, char *s2, int n)
{
    int i = 0;
    
    while (n > 0 && s1[i]) {
        if(s1[i] != s2[i])
            return (s1[i] - s2[i]);
        i++;
        n--;
    }
    return (0);
}
