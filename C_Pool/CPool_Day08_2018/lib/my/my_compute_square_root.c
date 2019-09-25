/*
** EPITECH PROJECT, 2018
** my_compute_square_root
** File description:
** Iterativ sqrt()
*/

int my_compute_square_root(int nb)
{
    int i = 1;
    int j = 0;

    while (j <= nb) {
        j = i * i;
	if (j == nb)
            return (i);
	else if (j < 0)
            return (0);
    }
    i++;
    return (0);
}
