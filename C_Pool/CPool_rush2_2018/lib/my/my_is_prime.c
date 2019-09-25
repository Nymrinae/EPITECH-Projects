/*
** EPITECH PROJECT, 2018
** isprime
** File description:
** isprime
*/

int my_is_prime(int nb)
{
    int div;
    int i;

    if (nb < 2 || (nb % 2 == 0 && nb != 2))
        return (0);
    for (i = 3; i * i <= nb; i += 2) {
        div = nb / i;
        if (nb == div * i)
            return (0);
    }
    return (1);
}
