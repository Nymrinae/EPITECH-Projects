/*
** EPITECH PROJECT, 2018
** Header
** File description:
** Header for rush3
*/

#ifndef _RUSH3_H_
#define _RUSH3_H_
#define BUFF_SIZE 30000

int    rush3(char *);
int     get_columns(char*);
int     get_rows(char*);
char    *last_c(char*);
void    get_rush_id(char*, int, int);
void    single_r_or_c(char*, int, int);
void    display(char *, int, int);

#endif
