/*
** EPITECH PROJECT, 2018
** my_putstr
** File description:
** The function displays
** one by one the characters
** of a string
*/

void    my_putchar(char c);

int    my_putstr(const char *str)
{
    int taille = 0;

    while (str[taille] != '\0')
    {
        my_putchar(str[taille]);
        taille++;
    }
}
