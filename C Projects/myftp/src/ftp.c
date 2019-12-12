/*
** EPITECH PROJECT, 2019
** myftp
** File description:
** ftp.c
*/

#include "myftp.h"

void run_ftp(struct sockaddr_in s, mysocket_t *srv_socket)
{
    fd_set read_fd_set;
    fd_set active_fd_set;
    mysocket_t *ctrl_socket;

    FD_ZERO(&active_fd_set);
    FD_SET(srv_socket->socket_id, &active_fd_set);
    ctrl_socket = build_socket();
    while (1) {
        read_fd_set = active_fd_set;
        if (select (FD_SETSIZE, &read_fd_set, NULL, NULL, NULL) < 0)
            print_err(SELECT);
        for (int i = 0; i < FD_SETSIZE; ++i)
            if (FD_ISSET(i, &read_fd_set)) {
                ctrl_socket->i = i;
                ctrl_socket->fdset = &active_fd_set;
                check_socket(ctrl_socket, s, srv_socket, &active_fd_set);
            }
    }
}

void check_socket(mysocket_t *ctrl_socket, struct sockaddr_in s,
mysocket_t *srv_socket, fd_set *active_fd_set)
{
    int id;
    int size = sizeof(s);
    int srv_id = srv_socket->socket_id;

    if (ctrl_socket->i == srv_id) {
        if ((id = accept(srv_id, (struct sockaddr *)&s, &size)) < 0)
            print_err(ACCEPT);
        ctrl_socket->msg = RC_220;
        ctrl_socket->socket_id = id;
        ctrl_socket->initial_path = srv_socket->initial_path;
        print_rc(ctrl_socket);
        FD_SET(ctrl_socket->socket_id, active_fd_set);
    } else {
        if (read_client(ctrl_socket->i, ctrl_socket) < 0) {
            close(ctrl_socket->i);
            FD_CLR(ctrl_socket->i, active_fd_set);
        }
    }
}

int read_client(int fd, mysocket_t *ctrl_socket)
{
    char buff[1024];
    int n = read(fd, buff, 1024);

    switch(n){
        case -1:
            print_err(READ);
            break;
        case 0:
            return -1;
            break;
        default:
            parse_buff(buff, ctrl_socket);
            print_cmd(ctrl_socket);
            reset_cmd(ctrl_socket);
            return 0;
            break;
    }
}