/*
** EPITECH PROJECT, 2018
** isupper
** File description:
** isupper
*/

int my_str_isupper(char const *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++) {
        if (str[i] > 'Z' || str[i] < 'A')
            return (0);
    }
    return (1);
}
