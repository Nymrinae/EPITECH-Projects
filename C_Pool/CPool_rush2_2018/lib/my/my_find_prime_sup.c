/*
** EPITECH PROJECT, 2018
** find prime sup
** File description:
** find prime sup
*/

#include "my.h"

int my_find_prime_sup(int nb)
{
    int prime_sup = 3;

    if (nb < 2)
        return (2);
    for (; !(my_is_prime(prime_sup) && prime_sup >= nb); prime_sup += 2);
    return (prime_sup);
}
