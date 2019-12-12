/*
** EPITECH PROJECT, 2019
** myftp
** File description:
** help.c
*/

#include "myftp.h"

void cmd_help(mysocket_t *s)
{
    char msg[256];

    sprintf(msg, "%s%s%s", RC_214_I, LIST_CMDS, RC_214_OK);
    s->msg = msg;
}