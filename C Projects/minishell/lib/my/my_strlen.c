/*
** EPITECH PROJECT, 2018
** MY_STRLEN
** File description:
** Count and returns the number of characters found in a string.
*/

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }

    return (i);
}
