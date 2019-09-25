/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main file for rush 3
*/

#include <unistd.h>
#include "../include/rush3.h"

int main()
{
    char buff[BUFF_SIZE + 1];
    int offset = 0;
    int len;
    
    while ((len = read(0, buff + offset, BUFF_SIZE - offset)) > 0) {
        offset += len;
    }
    buff[offset+1] = '\0';
    if (len < 0) {
        write(2, "Length is less than 0\n", 22);
        return (84);
    }
    rush3(buff);
    
    return (0);
}
