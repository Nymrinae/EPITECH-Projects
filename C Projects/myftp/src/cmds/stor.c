/*
** EPITECH PROJECT, 2019
** myftp
** File description:
** stor.c
*/

#include "myftp.h"

void cmd_stor(mysocket_t *s)
{
    s->msg = s->is_logged ? RC_150 : RC_530;
}