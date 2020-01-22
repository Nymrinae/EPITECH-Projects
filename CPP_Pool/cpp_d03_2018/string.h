/*
** EPITECH PROJECT, 2018
** string.h
** File description:
** Exercise 0 - My String
*/

#ifndef _STRING_H_
#define _STRING_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct s {
    char *str;
    void        (*assign_s)(struct s *, const struct s *);
    void        (*assign_c)(struct s *, const char *);
    void        (*append_s)(struct s *, const struct s *ap);
    void        (*append_c)(struct s *, const char *ap);
    char        (*at)(const struct s *, size_t pos);
    void        (*clear)(struct s *);
    int         (*size)(const struct s *);
    int         (*compare_s)(const struct s *, const struct s *str);
    int         (*compare_c)(const struct s *, const char *str);
    size_t      (*copy)(const struct s *, char *s, size_t n, size_t pos);
    const char  *(*c_str)(const struct s *);
    int         (*empty)(const struct s *);
    int         (*find_s)(const struct s *, const struct s *str, size_t pos);
    int         (*find_c)(const struct s *, char *str, size_t pos);
    void        (*insert_s)(struct s *, size_t pos, struct s *);
    void        (*insert_c)(struct s *, size_t pos, const char *str);
    int         (*to_int)(const struct s *);
    struct s ** (*split_s)(const struct s *, char separator);
    char **     (*split_c)(const struct s *, char separator);
    void        (*aff)(const struct s *);
} string_t;

void            string_init(string_t *this, const char *s);
void            string_destroy(string_t *this);

#endif