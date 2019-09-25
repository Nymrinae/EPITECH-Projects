/*
** EPITECH PROJECT, 2018
** cat main
** File description:
** reproduce behaviour of cat
*/

#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include "../include/my.h"
#include "../include/fct.h"

int main(int ac, char **av)
{
    int fd;
    int size;
    int i = 1;
    char buffer[30000];

    while (i != ac) {
        fd = open(av[i], O_RDONLY);
        if (fd == -1)
            read_err(errno);
        size = read(fd, buffer, 29999);
        my_putstr(buffer);
        ++i;
    }
    my_putchar('\n');
    close(fd);
    return (0);
}
