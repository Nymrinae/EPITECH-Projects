/*
** EPITECH PROJECT, 2018
** MY_GETNBR
** File description:
** Get numbers
*/

#include "my.h"

int is_neg(char const *str);

int my_getnbr(char const *str)
{
    int nbr = 0;
    int idx = 0;
    int sign = is_neg(str);

    while (str[idx] != '\0')
    {
        if (str[idx] >= '0' && str[idx] <= '9') {
            nbr *= 10;
            nbr += (str[idx] - 48);
            idx++;
        }
        else if (str[idx] <= '0' && str[idx] >= '9')
            return (nbr);
        else
            idx++;
    }
    if (nbr > 20000000000) return (0);
    if (sign == 0) return (nbr);
    else
        return (-nbr);
}

int is_neg(char const *str)
{
    int idx = 0;
    int sign = 0;

    while (str[idx] != '\0' && str[idx] == '-' || str[idx] == '+')
    {
        if (str[idx] == '-')
            sign++;
        idx++;
    }

    if (sign % 2 != 0)
        return (1);
    else
        return (0);
}
