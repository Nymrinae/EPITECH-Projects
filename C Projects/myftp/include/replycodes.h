/*
** EPITECH PROJECT, 2019
** myftp
** File description:
** Reply Codes Header
*/

#ifndef _RC_H_
#define _RC_H_

// Reply Codes Success
#define RC_120    "120 Service ready in nnn minutes.\n"
#define RC_125    "125 Data connection already open; transfer starting.\n"
#define RC_150    "150 File status okay; about to open data connection.\n"
#define RC_200    "200 Command okay.\n"
#define RC_214_I  "214 Help message.\n"
#define RC_214_OK "214 Help OK.\n"
#define RC_220    "220 Service ready for new user.\n"
#define RC_221    "221 Service closing control connection.\n"
#define RC_226_0  "226 Closing data connection\nRequested file action"
#define RC_226_1  " successful (for example, file transfer or file abort).\n"
#define RC_226    RC_226_0 RC_226_1
#define RC_227    "227 Entering Passive Mode (%d,%d,%d,%d,%d,%d).\n"
#define RC_230    "230 User logged in, proceed.\n"
#define RC_250    "250 Requested file action okay, completed.\n"
#define RC_257    "257 %s created.\n"
#define RC_331    "331 User name okay, need password.\n"
#define RC_332    "332 Need account for login.\n"

// Reply Codes Errors
#define RC_500   "500 Wrong command.\n"
#define RC_502   "502 Command doesn't exist or not implemented.\n"
#define RC_530   "530 Not logged in.\n"
#define RC_530_1 "530 Username incorrect.\n"
#define RC_550   "550 Requested action not taken. File unavailable.\n"

#endif