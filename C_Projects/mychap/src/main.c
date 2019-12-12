/*
** EPITECH PROJECT, 2019
** mychap
** File description:
** main.c
*/

#include "mychap.h"

int main(int ac, char **av)
{
    opt_t *args = init_options();
    mysocket_t *srv_socket = build_socket();

    if (parse_args(args, ac, av) != 84) {
        srv_socket->socket_id = init_socket(args);
        run_chap(srv_socket, args);
    } else
        return 84;

    return EXIT_SUCCESS;
}