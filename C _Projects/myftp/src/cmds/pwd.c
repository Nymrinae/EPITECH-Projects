/*
** EPITECH PROJECT, 2019
** myftp
** File description:
** pwd.c
*/

#include "myftp.h"

void cmd_pwd(mysocket_t *s)
{
    char msg[256];
    char pwd[256];

    if (s->is_logged) {
        getcwd(pwd, sizeof(pwd));
        sprintf(msg, RC_257, pwd);
    } else
        strcpy(msg, RC_530);
    s->msg = msg;
}