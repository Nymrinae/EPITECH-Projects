/*
** EPITECH PROJECT, 2019
** myftp
** File description:
** noop.c
*/

#include "myftp.h"

void cmd_noop(mysocket_t *s)
{
    s->msg = (s->is_logged) ? RC_200 : RC_530;
}