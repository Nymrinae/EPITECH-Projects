/*
** EPITECH PROJECT, 2019
** myftp
** File description:
** Errors strings header
*/

#ifndef _STR_H_
#define _STR_H_

// Strings
#define HELP_P1 " CDUP CWD DELE HELP LIST NOOP PASS "
#define HELP_P2 "PASV PORT PWD QUIT RETR STOR USER\n"
#define LIST_CMDS    HELP_P1 HELP_P2

// Errors
#define READ              "[ERROR] Cannot read socket."
#define SELECT            "[ERROR] Select error."
#define BIND              "[ERROR] Bind error."
#define FORK              "[ERROR] Fork error."
#define ACCEPT            "[ERROR] Accept error."
#define SOCKET_CONNECT    "[ERROR] Socket can't connect."
#define SOCKET_CREATE     "[ERROR] Socket can't be created."
#define SOCKET_OPTION     "[ERROR] Sockets options are wrong."
#define MISSING_PARAMS    "[ERROR] Missing parameters. Check ./myftp -help"
#define INCORRECT_PORT    "[ERROR] Port number incorrect. Check ./myftp -help"

#endif
