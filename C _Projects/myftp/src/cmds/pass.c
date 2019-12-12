/*
** EPITECH PROJECT, 2019
** myftp
** File description:
** pass.c
*/

#include "myftp.h"

void cmd_pass(mysocket_t *s)
{
    if (s->login_ok) {
        s->is_logged = 1;
        s->msg = RC_230;
    } else
        s->msg = RC_530_1;
}