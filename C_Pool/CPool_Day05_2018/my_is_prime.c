/*
** EPITECH PROJECT, 2018
** my_is_prime
** File description:
** Returns 1 if the number is prime, 0 is not
*/

int my_is_prime(int nb)
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
