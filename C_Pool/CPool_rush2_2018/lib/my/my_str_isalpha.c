/*
** EPITECH PROJECT, 2018
** isalpha
** File description:
** isalpha
*/

int my_str_isalpha(char const *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++) {
        if (str[i] < 'A' || (str[i] > 'Z' && str[i] < 'a') || str[i] > 'z')
            return (0);
    }
    return (1);
}
