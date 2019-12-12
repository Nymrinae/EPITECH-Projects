/*
** EPITECH PROJECT, 2019
** mychap
** File description:
** args.c
*/

#include "mychap.h"

int has_right_opt(int ac, char **av)
{
    if (ac != 7)
        return 84;
    return (((!strcmp("-t", av[1])) || (!strcmp("-target", av[1])))
    && ((!strcmp("-p", av[3])) || (!strcmp("-port", av[3])))
    && ((!strcmp("-P", av[5])) || (!strcmp("-password", av[5]))));
}

int is_ip_correct(char *ip)
{
    int nb_pts = 0;

    if (strlen(ip) > 12)
        exit(84);

    for (int i = 0; ip[i]; i++) {
        if (ip[i] == '.')
            nb_pts++;
        if (ip[i] != '.' && (ip[i] < '0' || ip[i] > '9')) {
            printf("No such hostname: '%s'\n", ip);
            exit(84);
        }
    }
    return (nb_pts == 3);
}

void check_ip(char **av, opt_t *args)
{
    int correct_ip = 0;

    if (!strcmp(av[2], "localhost")) {
        args->target = "127.0.0.1";
        return;
    }
    is_ip_correct(av[2]) ? args->target = av[2] : exit(84);
}

void check_port( char **av, opt_t *args)
{
    int port = atoi(av[4]);

    if (port < 0)
        exit(84);
    args->port = port;
}

int parse_args(opt_t *args, int ac, char **av)
{
    if (has_right_opt(ac, av) != 84) {
        check_ip(av, args);
        check_port(av, args);
        args->password = av[6];
        return 1;
    } else
        return 84;
}