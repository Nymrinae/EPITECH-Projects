/*
** EPITECH PROJECT, 2018
** strlen
** File description:
** strlen
*/

int my_strlen(char const *str)
{
    int len;

    for (len = 0; *(str + len) != '\0'; len++);
    return (len);
}
