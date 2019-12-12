/*
** EPITECH PROJECT, 2019
** myftp
** File description:
** main.c
*/

#ifndef _MYFTP_H
#define _MYFTP_H

#include <time.h>
#include <ctype.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <dirent.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <netinet/in.h>

// defines
#include "errors.h"
#include "strings.h"
#include "replycodes.h"

typedef struct port
{
    int p1;
    int p2;
    int pasv_port;
} port_t;

typedef struct mysocket
{
    int i;
    int socket_id;
    fd_set *fdset;
    int login_ok;
    int is_logged;
    char *msg;
    char *cmd;
    char *cmdarg;
    port_t *port;
    char *initial_path;
} mysocket_t;

static const char *cmds[] =
{
    "CWD", "CDUP", "DELE", "HELP", "LIST", "NOOP", "PASS",
    "PASV", "PORT", "PWD","RETR", "STOR", "QUIT", "USER",
};

typedef enum
{
    CWD, CDUP, DELE, HELP, LIST, NOOP, PASS,
    PASV, PORT, PWD, RETR, STOR, QUIT, USER,
} cmd_t;

// init.c
mysocket_t          *build_socket(void);
struct sockaddr_in  *init_sockaddr(int port);
int                 init_socket(struct sockaddr_in s);

// ftp.c
int     read_client(int fd, mysocket_t *);
void    run_ftp(struct sockaddr_in, mysocket_t *);
void    check_socket(mysocket_t *, struct sockaddr_in, mysocket_t *, fd_set *);

// print.c
void    print_err(char *);
void    print_rc(mysocket_t *);
void    print_cmd(mysocket_t *s);
int     check_args(int, char **);

// parsing.c
int     check_cmd(char *);
int     reset_cmd(mysocket_t *);
void    parse_buff(char *, mysocket_t *);

// {commands}.c
void    cmd_cdup(mysocket_t *s);
void    cmd_cwd(mysocket_t *s);
void    cmd_dele(mysocket_t *s);
void    cmd_help(mysocket_t *s);
void    cmd_list(mysocket_t *s);
void    cmd_noop(mysocket_t *s);
void    cmd_pass(mysocket_t *s);
void    cmd_pasv(mysocket_t *s);
void    cmd_port(mysocket_t *s);
void    cmd_pwd(mysocket_t *s);
void    cmd_quit(mysocket_t *s);
void    cmd_retr(mysocket_t *s);
void    cmd_stor(mysocket_t *s);
void    cmd_user(mysocket_t *s);

#endif