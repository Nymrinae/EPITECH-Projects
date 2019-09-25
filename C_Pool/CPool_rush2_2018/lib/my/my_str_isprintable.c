/*
** EPITECH PROJECT, 2018
** isprintable
** File description:
** isprintable
*/

int my_str_isprintable(char const *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++) {
        if (str[i] > '~' || str[i] < ' ')
            return (0);
    }
    return (1);
}
