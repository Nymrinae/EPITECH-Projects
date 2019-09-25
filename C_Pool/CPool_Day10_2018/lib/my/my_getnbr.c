/*
** EPITECH PROJECT, 2018
** my_getnbr
** File description:
**  jle fait 6 jours apres ez
*/

int my_getnbr(char const *str)
{
    int i = 0;
    int nb = 0;
    int neg = 1;

    while((str[i] >= '0' && str[i] <= '9') || str[i] == '-') {
        if (str[i] == '-')
            neg *= -1;
        if(str[i] >= '0' && str[i] <= '9') // need 2 replace it w/ is_num()
            nb = (nb * 10) + str[i] - 48;
        ++i;
    }
    return (nb * neg);
}
