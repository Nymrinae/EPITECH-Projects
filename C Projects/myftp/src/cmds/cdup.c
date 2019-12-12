/*
** EPITECH PROJECT, 2019
** myftp
** File description:
** cdup.c
*/

#include "myftp.h"

void cmd_cdup(mysocket_t *s)
{
    if (s->is_logged)
        s->msg = (!chdir("..")) ? RC_250 : RC_550;
    else
        s->msg = RC_530;
}