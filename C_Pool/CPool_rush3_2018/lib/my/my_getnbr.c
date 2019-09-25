/*
** EPITECH PROJECT, 2018
** my_getnbr
** File description:
** This function return a number
** send as a string
*/

void  my_putchar(char c);

int is_neg(char *str);

int	my_getnbr(char *str)
{
    int	nbr = 0;
    int	idx = 0;
    is_neg(str);
    while (str[idx] != '\0')
    {
        if (str[idx] >= '0' && str[idx] <= '9')
        {
            nbr *= 10;
            nbr += (str[idx] - 48);
            idx++;
        }
        else if (str[idx] <= '0' && str[idx] >= '9')
            return (nbr);
        else
            idx++;
    }
    if (nbr > 20000000000)
        return (0);
    return (nbr);
}

int is_neg(char *str)
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
        my_putchar('-');
}