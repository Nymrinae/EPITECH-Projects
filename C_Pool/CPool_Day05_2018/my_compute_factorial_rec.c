/*
** EPITECH PROJECT, 2018
** my_compute_factorial_rec.c
** File description:
** Returns the factorial of the number given as a parameter (recursiv)
*/

int my_compute_factorial_rec(int nb)
{
    if (nb < 0 || nb > 12)
	return (0);
    if (nb == 0 || nb == 1)
	return (1);
    return nb * my_compute_factorial_rec(nb - 1);   
}

