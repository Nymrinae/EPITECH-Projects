/*
** EPITECH PROJECT, 2019
** myftp
** File description:
** print.c
*/

#include "myftp.h"

int check_cmd(char *cmd)
{
    for (int i = 0; i < 14; i++)
        if (!strcmp(cmd, cmds[i]))
            return i;
    return 84;
}

int reset_cmd(mysocket_t *s)
{
    s->msg = "";
    s->cmd[0] = '\0';
    s->cmdarg[0] = '\0';
}

void parse_buff(char *buff, mysocket_t *s)
{
    char prout[20];
    char cmd[5];
    char cmdarg[10];

    strcpy(prout, buff);
    sscanf(prout, "%s %s ", s->cmd, s->cmdarg);
}