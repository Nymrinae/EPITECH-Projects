/*
** EPITECH PROJECT, 2019
** mychap
** File description:
** chap.c
*/

#include "mychap.h"

unsigned short checksum(unsigned short *buf, int nwords)
{
    unsigned long sum;

    for (sum = 0; nwords > 0; nwords--)
        sum += *buf++;
    sum = (sum >> 16) + (sum &0xffff);
    sum += (sum >> 16);

    return (unsigned short)(~sum);
}

void fill_headers(iph_t *iph, udph_t *udph, opt_t *args)
{
    char buffer[PACKET_LENGTH];

    iph->ihl = 5;
    iph->ver = 4;
    iph->tos = 16;
    iph->len = sizeof(iph_t) + sizeof(udph_t);
    iph->ident = htons(54321);
    iph->ttl = 64;
    iph->protocol = 17;
    iph->sourceip = inet_addr(args->target);
    iph->destip = iph->sourceip;

    udph->length = htons(sizeof(udph_t));
    udph->srcport = htons(args->port);
    udph->destport = udph->srcport;

    iph->checksum = checksum((unsigned short *)buffer,
    sizeof(iph_t) + sizeof(udph_t));
}

int run_chap(mysocket_t *sock, opt_t *args)
{
    char buffer[PACKET_LENGTH];
    iph_t *iph = (iph_t *)buffer;
    udph_t *udph = (udph_t *)(buffer + sizeof(iph_t));

    memset(buffer, 0, PACKET_LENGTH);
    fill_headers(iph, udph, args);
    printf("KO\n");
}