/*
** EPITECH PROJECT, 2018
** my_revstr
** File description:
** This function reverses a string
*/

int    my_strlen(const char *str);

char    *my_revstr(char *str)
{
    int idx = 0;
    int lenght = my_strlen(str) - 1;
    char temp;

    while (idx <= lenght / 2)
    {
        temp = str[idx];
        str[idx] = str[lenght - idx];
        str[lenght - idx] = temp;
        idx++;
    }

    return (str);
}
