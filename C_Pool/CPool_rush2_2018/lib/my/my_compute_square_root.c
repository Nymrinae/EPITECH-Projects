/*
** EPITECH PROJECT, 2018
** square root
** File description:
** square root
*/

int my_compute_square_root(int nb)
{
    int i;

    if (nb <= 0)
        return (0);
    for (i = 1; 1; i++) {
        if (i * i == nb)
            return (i);
        if (i > nb / 2)
            return (0);
    }
}
