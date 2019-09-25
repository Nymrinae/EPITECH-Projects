/*
** EPITECH PROJECT, 2018
** my_str_isprintable
** File description:
** Returns either 1 || 0 if the string only
*/

int my_str_isprintable(char const *str)
{
    int i = 0;

    while (str[i]) {
        if (str[i] >= 0 || str[i] < 32)
            return (1);
        i++;
    }
    return (0);
}
