/*
** EPITECH PROJECT, 2019
** myftp
** File description:
** pasv.c
*/

#include "myftp.h"

void create_port(mysocket_t *s)
{
    srand(time(NULL));

    int p1 = rand() % 255;
    int p2 = rand() % 255;
    int p3 = 256 * p1 + p2;

    s->port->p1 = p1;
    s->port->p2 = p2;
    s->port->pasv_port = p3;
}

int *get_ip(mysocket_t *s)
{
    char *ip_str;
    struct sockaddr_in addr;
    int size = sizeof(addr);
    int *ip = malloc(sizeof(int) * 4);

    getsockname(s->socket_id, (struct sockaddr *)&addr, &size);
    ip_str = inet_ntoa(addr.sin_addr);
    sscanf(ip_str, "%d.%d.%d.%d", &ip[0], &ip[1], &ip[2], &ip[3]);

    return (ip);
}

void cmd_pasv(mysocket_t *s)
{
    int p1;
    int p2;
    int *ip = malloc(sizeof(int) * 4);
    char *buff = malloc(sizeof(char) * 255);

    if (s->is_logged) {
        create_port(s);
        ip = get_ip(s);
        p1 = s->port->p1;
        p2 = s->port->p2;
        sprintf(buff, RC_227, ip[0], ip[1], ip[2], ip[3], p1, p2);
        s->msg = buff;
    } else
        s->msg = RC_530;
}