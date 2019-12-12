/*
** EPITECH PROJECT, 2019
** myftp
** File description:
** init.c
*/

#include "myftp.h"

mysocket_t *build_socket(void)
{
    mysocket_t *user = malloc(sizeof(mysocket_t));
    port_t *port = malloc(sizeof(port_t));

    port->p1 = 0;
    port->p2 = 0;
    port->pasv_port = 0;

    user->login_ok = 0;
    user->is_logged = 0;
    user->msg = "";
    user->cmd = malloc(sizeof(char) * 4);
    user->cmdarg = malloc(sizeof(char) * 256);
    user->port = port;

    return (user);
}

struct sockaddr_in *init_sockaddr(int port)
{
    struct sockaddr_in *sock = malloc(sizeof(struct sockaddr_in));

    sock->sin_family = AF_INET;
    sock->sin_addr.s_addr = INADDR_ANY;
    sock->sin_port = htons(port);

    return (sock);
}

int init_socket(struct sockaddr_in s)
{
    int sock;
    int opt = 1;

    if (!(sock = socket(AF_INET, SOCK_STREAM, 0)))
        print_err(SOCKET_CREATE);
    if (setsockopt(sock, SOL_SOCKET, 2 | 15, &opt, sizeof(opt)) < 0)
        print_err(SOCKET_CREATE);
    if (bind(sock, (struct sockaddr *)&s, sizeof(s)) < 0)
        print_err(BIND);
    listen(sock, 16);

    return (sock);
}