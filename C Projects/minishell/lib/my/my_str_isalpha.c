/*
** EPITECH PROJECT, 2018
** my_str_isalpha
** File description:
** Returns 1 if the string contains alphabetical characters and 0 else.
*/

int my_str_isalpha(char const *str)
{
    int i = 0;
    int result = 1;

    for (i = 0; str[i]; i++) {
        if (str[i] < 65)
            return (0);
        if ((str[i] > 90) && (str[i] < 97))
            return (0);
        if (str[i] > 122)
            return (0);
    }

    return (result);
}
