/*
** EPITECH PROJECT, 2018
** my_compute_factorial_it
** File description:
** Returns the factorial of the number given as a parameter (iterative)
*/

int my_compute_factorial_it(int nb)
{
    int f = 1;

    if (nb < 0 || nb > 12)
	    return (0);
    
    for (int i = 1; i <= nb; i++) {
	    f *= i;
    }
    return (f);
}
