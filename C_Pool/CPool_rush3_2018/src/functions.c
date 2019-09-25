/*
** EPITECH PROJECT, 2018
** functions
** File description:
** functions used for rush3
*/

#include <stdlib.h>
#include "../include/rush3.h"
#include "../include/my.h"

int get_columns(char *str)
{
    int c = 0;
    int i = 0;
    
    while (str[i] != '\n') {
        c++;
        i++;
    }
    return (c);
}

int get_rows(char *str)
{
    int r = 0;
    int i = 0;

    while (str[i]) {
        if (str[i] == '\n')
            r++;
        i++;
    }
    return (r);
}

char *last_c(char *str)
{
    int i = 0;
    int j = 0;
    int columns = get_columns(str);
    char *new_str = malloc(columns * sizeof(char));
    char *border_c = malloc(2 * sizeof(char));
    
    while (str[i]) {
        if (str[i] == '\n'){
            new_str[j] = str[i - 1];
            j++;
        }
        i++;
    }
    new_str[j] = '\0';
    border_c[0] = new_str[0];
    border_c[1] = new_str[j - 1];
    border_c[2] = '\0';
    
    return (border_c);
}

void get_rush_id(char *str, int c, int r)
{
    char id1[] = "oo";
    char id2[] = "\\/";
    char id3[] = "AC";
    char id4[2] = "CC";
    char id5[2] = "CA";
    
    if (*str == *id1)
        display("[rush1-1]", c, r);
    if (*str == *id2)
        display("[rush1-2]", c, r);
    if (*str == *id3)
        display("[rush1-3]", c, r);
    if ((str[0] == id4[0]) && (str[1] == id4[1]))
        display("[rush1-4]", c, r);
    if ((str[0] == id5[0]) && (str[1] == id5[1]))
        display("[rush1-5]", c, r);
    my_putchar('\n');
}

void single_r_or_c(char *str, int c, int r)
{
    int i = 0;

    if (str[i] == 'o') {
        display("[rush 1-1]", c, r);
        my_putchar('\n');
    } else if (str[i] == '*') {
        display("[rush 1-2]", c, r);
        my_putchar('\n');
    } else {
        display("[rush 1-3]", c, r);
        my_putstr(" || ");
        display("[rush 1-4]", c, r);
        my_putstr(" || ");
        display("[rush 1-5]", c, r);
        my_putchar('\n');
    }
}
