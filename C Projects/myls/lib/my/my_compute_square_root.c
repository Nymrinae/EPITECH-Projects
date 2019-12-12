/*
** EPITECH PROJECT, 2018
** my_compute_square_root
** File description:
** This is
*/

int    my_compute_square_root(int nb)
{
    int idx;

    for (idx = 0; (idx * idx) != nb; idx++) {
        if ((idx * idx) > nb)
            return 0;
    }
    return ((idx < 0) ? 1 : idx);
}
