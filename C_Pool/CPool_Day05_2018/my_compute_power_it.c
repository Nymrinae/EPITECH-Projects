/*
** EPITECH PROJECT, 2018
** my_compute_power_it
** File description:
** Returns the first argument raised to power p (iterativ)
*/

int my_compute_power_it(int nb, int p)
{
    int n = 1;
    
    if (p < 0)
        return(0);
    if (p == 0)
	return(1);
    for (int i = 0; i < p; i++) {
	    n *= nb;
    }
    return (n);
}
