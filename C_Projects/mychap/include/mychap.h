/*
** EPITECH PROJECT, 2019
** myftp
** File description:
** cwd.c
*/

#ifndef _MYCHAP_H_
#define _MYCHAP_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include "errors.h"

#define PACKET_LENGTH 8192

typedef struct opt
{
    char    *target;
    int     port;
    char    *password;
} opt_t;

typedef struct mysocket
{
    int socket_id;
} mysocket_t;

typedef struct ipheader {
    unsigned char       ihl;
    unsigned char       ver;
    unsigned char       tos;
    unsigned short int  len;
    unsigned short int  ident;
    unsigned char       flag;
    unsigned short int  offset;
    unsigned char       ttl;
    unsigned char       protocol;
    unsigned short int  checksum;
    unsigned int        sourceip;
    unsigned int        destip;
} iph_t;

typedef struct udpheader {
    unsigned short int srcport;
    unsigned short int destport;
    unsigned short int length;
    unsigned short int checksum;
} udph_t;
// init.c
int         init_socket(opt_t *);
opt_t       *init_options(void);
mysocket_t  *build_socket(void);

// args.c
int         has_right_opt(int, char **);
void        check_ip( char **, opt_t *);
void        check_port( char **, opt_t *);
int         parse_args(opt_t *, int, char **);

// chap.c
int         run_chap(mysocket_t *, opt_t *);
void        fill_headers(iph_t *iph, udph_t *udph, opt_t *args);

#endif