/*
** EPITECH PROJECT, 2018
** my_find_prime_sup
** File description:
** Smallest prime number > to nb
*/

int is_first(int nb)
{
    int i = 3;
    
    if (nb < 2)
        return (0);
    if (nb == 2)
        return (1);
    while (i  <= nb / 2) {
        if (nb % i == 0)
            return(0);
        i++;
    }
    return (1);
}

int my_find_prime_sup(int nb)
{
    if (nb > 2 && nb % 2 == 0)
        nb++;
    while (!is_first(nb))
        nb += 2;
    return (nb);
}
