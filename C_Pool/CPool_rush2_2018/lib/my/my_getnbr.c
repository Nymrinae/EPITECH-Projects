/*
** EPITECH PROJECT, 2018
** getnbr
** File description:
** getnbr
*/

static int is_digit(char c)
{
    return (c >= '0' && c <= '9');
}

int my_getnbr(char const *str)
{
    int i = 0;
    int neg = 1;
    int result = 0;

    for (; str[i] > '9' || str[i] < '0'; i++) {
        if (str[i] == '-')
            neg *= -1;
    }
    for (; is_digit(str[i]); i++) {
        result *= 10;
        result += (str[i] - '0') * neg;
        if ((result >= 0) != (neg >= 0))
            return (0);
    }
    return (result);
}
