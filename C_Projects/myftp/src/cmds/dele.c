/*
** EPITECH PROJECT, 2019
** myftp
** File description:
** dele.c
*/

#include "myftp.h"

void cmd_dele(mysocket_t *s)
{
    if (s->is_logged)
        s->msg = (!remove(s->cmdarg)) ? RC_250 : RC_550;
    else
        s->msg = RC_530;
}