/*
** EPITECH PROJECT, 2018
** my_find_prime_sup
** File description:
** Returns the smallest biggest number after the number passed as parameter
*/

int is_first(int nb)
{
    int i = 3;
    
    if (nb < 2)
	return (0);
    if (nb == 2)
	return (1);
    while (i  <= nb / 2) {
	if (nb % i == 0) {
	    return(0);
        }
	i = i + 1;
    }
    return (1);
}

int my_find_prime_sup(int nb)
{
    if (nb > 2 && nb % 2 == 0) {
	nb++;
    }
    while (!is_first(nb)) {
	nb += 2;
    }    
    return (nb);
}
