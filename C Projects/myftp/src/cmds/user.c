/*
** EPITECH PROJECT, 2019
** myftp
** File description:
** user.c
*/

#include "myftp.h"

void cmd_user(mysocket_t *s)
{
    if (!strcmp(s->cmdarg, "Anonymous"))
        s->login_ok = 1;
    s->msg = RC_331;
}