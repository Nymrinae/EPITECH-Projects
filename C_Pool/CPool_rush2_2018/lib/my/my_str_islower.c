/*
** EPITECH PROJECT, 2018
** islower
** File description:
** islower
*/

int my_str_islower(char const *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++) {
        if (str[i] > 'z' || str[i] < 'a')
            return (0);
    }
    return (1);
}
