/*
** EPITECH PROJECT, 2018
** my_strlen
** File description:
** This function display
** the lenght of a string
*/

int    my_strlen(const char *str)
{
    int taille = 0;

    while (str[taille] != '\0')
    {
        taille++;
    }

    return (taille);
}