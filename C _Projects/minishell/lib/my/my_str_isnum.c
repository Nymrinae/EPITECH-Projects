/*
** EPITECH PROJECT, 2018
** my_str_isnum
** File description:
** Returns 1 if the string contains digits and 0 otherwise.
*/

int my_str_isnum(char const *str)
{
    int i = 0;
    int result = 1;

    for (i = 0; str[i]; i++) {
        if ((str[i] < 48) || (str[i] > 57))
            return (0);
    }

    return (result);
}
