/*
** EPITECH PROJECT, 2019
** myftp
** File description:
** print.c
*/

#include "myftp.h"

void usage(void)
{
    printf("USAGE: ./myftp port path\n");
    printf("\tport is the port number no which the server socket listens\n");
    printf("\tpath is the path to the home directory for the Anonymous user\n");
    exit(84);
}

int check_args(int ac, char **av)
{
    if (!strcmp(av[1], "-help"))
        usage();
    if (ac != 3)
        print_err(MISSING_PARAMS);
    if (atoi(av[1]) <= 0)
        print_err(INCORRECT_PORT);
    if (opendir(av[2]) == NULL)
        return 84;
    return (1);
}

void print_err(char *str)
{
    fprintf(stderr, "%s\n", str);
    exit(84);
}

void print_rc(mysocket_t *s)
{
    write(s->socket_id, s->msg, strlen(s->msg));
}

void print_cmd(mysocket_t *s)
{
    switch(check_cmd(s->cmd)){
        case CWD:  cmd_cwd(s);  break;
        case CDUP: cmd_cdup(s); break;
        case DELE: cmd_dele(s); break;
        case HELP: cmd_help(s); break;
        case LIST: cmd_list(s); break;
        case NOOP: cmd_noop(s); break;
        case PASS: cmd_pass(s); break;
        case PASV: cmd_pasv(s); break;
        case PORT: cmd_port(s); break;
        case PWD:  cmd_pwd(s);  break;
        case RETR: cmd_retr(s); break;
        case STOR: cmd_stor(s); break;
        case QUIT: cmd_quit(s); break;
        case USER: cmd_user(s); break;
        default:
            s->msg = RC_500;
        break;
    }
    print_rc(s);
}
