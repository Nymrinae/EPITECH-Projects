/*
** EPITECH PROJECT, 2018
** my_is_prime
** File description:
** This is function say if nb is prime
*/

int    my_is_prime(int nb)
{
    int idx = 2;

    if (nb <= 1)
        return (0);

    while (idx < nb)
    {
        if (nb % idx == 0)
            return (0);
        idx++;
    }
    return (1);
}