/*
** EPITECH PROJECT, 2018
** rush3
** File description:
** rush3 file
*/

#include <unistd.h>
#include "../include/rush3.h"
#include "../include/my.h"

int rush3(char *str)
{
    int c = get_columns(str);
    int r = get_rows(str);

    if (c <= 0 || r <= 0) {
        write(2, "Columns or rows cannot be equal or inferior than 0.\n", 53); 
        return (84);
    }
    if (c == 1 || r == 1) {
        single_r_or_c(str, c , r);
        return (0);
    }    
    get_rush_id(last_c(str), c, r);
    return (0);
}
