/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** This file is the header
** of libmy.a
*/

#ifndef _LIBMY_H_
#define _LIBMY_H_

void	my_putchar(char c);
int	my_isneg(int nb);
int	my_put_nbr(int nb);
void	my_swap(int *a, int *b);
int	my_putstr(char const *);
int	my_strlen(char const *);
int	my_getnbr(char const *);
void	my_sort_int_array(int *tab, int size);
int	my_compute_power_rec(int nb, int power);
int	my_compute_square_root(int nb);
int	my_is_prime(int nb);
int	my_find_prime_sup(int nb);
char	*my_strcpy(char *, char const *);
char	*my_strncpy(char *, char const *, int);
char	*my_revstr(char *);
char	*my_strstr(char const *, char const *);
int	my_strcmp(char const *, char const *);
int	my_strncmp(char const *, char const *, int);
char	*my_strupcase(char *);
char	*my_strlowcase(char *);
char	*my_strcapitalize(char *);
int	my_str_isalpha(char const *);
int	my_str_isnum(char const *);
int	my_str_islower(char const *);
int	my_str_isupper(char const *);
int	my_str_isprintable(char const *);
int	my_showstr(char const *);
int	my_showmem(char const *, int);
char	*my_strcat(char *, char const *);
char	*my_strncat(char *, char const *, int);
int     my_set_value(char const **str);

#endif
