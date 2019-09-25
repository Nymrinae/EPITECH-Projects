/*
** EPITECH PROJECT, 2018
** power rec
** File description:
** power rec
*/

static int power_rec(int nb, int p)
{
    return (p != 0 ? (power_rec(nb, p - 1) * nb) : 1);
}

int my_compute_power_rec(int nb, int p)
{
    return (p < 0 ? 0 : power_rec(nb, p));
}
