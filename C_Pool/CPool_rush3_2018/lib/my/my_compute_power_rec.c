/*
** EPITECH PROJECT, 2018
** my_compute_power_rec
** File description:
** This function return the
** power with two int
*/

int    my_compute_power_rec(int nb, int power)
{
    if (power == 0)
        return (1);
    else if (power < 0)
        return (0);

    while (power > 1)
    {
        return (nb = (my_compute_power_rec(nb, power - 1)) * nb);
    }
}