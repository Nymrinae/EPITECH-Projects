/*
** EPITECH PROJECT, 2019
** myftp
** File description:
** cwd.c
*/

#include "myftp.h"

void dirhome(mysocket_t *s)
{
    fprintf(stderr, "%s\n", s->initial_path);
    s->msg = (!chdir(s->initial_path)) ? RC_250 : RC_550;
}

void cmd_cwd(mysocket_t *s)
{
    if (s->is_logged) {
        if (!strcmp(s->cmdarg, "~"))
            dirhome(s);
        else
            s->msg = (!chdir(s->cmdarg)) ? RC_250 : RC_550;
    } else
        s->msg = RC_530;
}