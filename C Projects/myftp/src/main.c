/*
** EPITECH PROJECT, 2019
** myftp
** File description:
** main.c
*/

#include "myftp.h"

int main(int ac, char **av)
{
    struct sockaddr_in *s = init_sockaddr(atoi(av[1]));
    mysocket_t *srv_socket = build_socket();

    srv_socket->socket_id = init_socket(*s);
    if (check_args(ac, av) != 84) {
        srv_socket->initial_path = av[2];
        chdir(srv_socket->initial_path);
        run_ftp(*s, srv_socket);
        return EXIT_SUCCESS;
    } else
        return 84;
}