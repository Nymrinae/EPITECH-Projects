/*
** EPITECH PROJECT, 2018
** my_set_value
** File description:
** This function transform
** ascii to value
*/

int my_set_value(char const **str)
{
    int asc_value = 0;
    while (**str >= 48 && **str <= 57) {
        asc_value *= 10;
        asc_value += (**str - 48);
        (*str)++;
    }
    return (asc_value);
}