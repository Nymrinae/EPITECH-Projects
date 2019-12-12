/*
** EPITECH PROJECT, 2019
** myftp
** File description:
** retr.c
*/

#include "myftp.h"

void cmd_retr(mysocket_t *s)
{
    s->msg = s->is_logged ? RC_150 : RC_530;
}