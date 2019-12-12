/*
** EPITECH PROJECT, 2019
** myftp
** File description:
** quit.c
*/

#include "myftp.h"

void cmd_quit(mysocket_t *s)
{
    char msg[256];

    s->msg = RC_221;
    print_rc(s);

    if (s->is_logged) {
        s->is_logged = 0;
        close(s->socket_id);
        FD_CLR(s->socket_id, s->fdset);
        s->is_logged = 0;
    } else {
        close(s->socket_id);
        FD_CLR(s->socket_id, s->fdset);
    }
}