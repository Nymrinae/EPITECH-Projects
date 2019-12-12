/*
** EPITECH PROJECT, 2018
** my_find_prime_sup
** File description:
** This function return the smallest
** prime number greater or equal
** to nb
*/

int    my_is_prime(int nb);

int    my_find_prime_sup(int nb)
{
    while (my_is_prime(nb) != 1)
        nb++;
    return (nb);
}
