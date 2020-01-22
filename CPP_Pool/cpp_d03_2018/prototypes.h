/*
** EPITECH PROJECT, 2018
** prototypes.h
** File description:
** Exercise 0 - My String
*/

#ifndef _PROTO_H_
#define _PROTO_H_

#include "string.h"

// Prototypes
void        assign_s(string_t *, const string_t *);
void        assign_c(string_t *, const char *);
void        append_s(string_t *, const string_t *ap);
void        append_c(string_t *, const char *ap);
char        at(const string_t *, size_t pos);
void        clear(string_t *);
int         size(const string_t *);
int         compare_s(const string_t *this, const string_t *str);
int         compare_c(const string_t *this, const char *str);
size_t      copy(const string_t *this, char *s, size_t n, size_t pos);
const char  *c_str(const struct s *);
int         empty(const struct s *);
int         find_s(const struct s *, const struct s *str, size_t pos);
int         find_c(const struct s *, char *str, size_t pos);
void        insert_s(struct s *, size_t pos, struct s *);
void        insert_c(struct s *, size_t pos, const char *str);
int         to_int(const struct s *);
struct s ** split_s(const struct s *, char separator);
char **     split_c(const struct s *, char separator);
void        aff(const struct s *);

#endif