/*
** EPITECH PROJECT, 2019
** mychap
** File description:
** init.c
*/

#include "mychap.h"

opt_t *init_options(void)
{
    opt_t *option = malloc(sizeof(opt_t));

    option->port = 0;
    option->target = malloc(sizeof(char) * 48);
    option->password = malloc(sizeof(char) * 256);

    return (option);
}

int init_socket(opt_t *opt)
{
    int sock;
    int i = 1;
    const int *XD = &i;
    struct sockaddr_in *s = malloc(sizeof(struct sockaddr_in));

    s->sin_family = AF_INET;
    s->sin_addr.s_addr = inet_addr(opt->target);
    s->sin_port = htons(opt->port);

    sock = socket(AF_INET, SOCK_RAW, IPPROTO_RAW);
    setsockopt(sock, IPPROTO_IP, IP_HDRINCL, XD, sizeof(i));
    bind(sock, (struct sockaddr *)&s, sizeof(s) < 0);
    listen(sock, 16);

    return (sock);
}

mysocket_t *build_socket(void)
{
    mysocket_t *client = malloc(sizeof(mysocket_t));

    client->socket_id = 0;

    return (client);
}