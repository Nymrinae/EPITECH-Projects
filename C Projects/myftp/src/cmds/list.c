/*
** EPITECH PROJECT, 2019
** myftp
** File description:
** list.c
*/

#include "myftp.h"

void cmd_list(mysocket_t *s)
{
    s->msg = s->is_logged ? RC_150 : RC_530;
}