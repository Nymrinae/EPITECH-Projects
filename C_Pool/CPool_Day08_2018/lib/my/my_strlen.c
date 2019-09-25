/*
** EPITECH PROJECT, 2018
** my_strlen
** File description:
** Counts the number of characters in a string
*/

int my_strlen(char const *str)
{
    int i = 0;

    while(str[i])
        i++;
    return (i);
}
