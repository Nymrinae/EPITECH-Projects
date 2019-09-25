/*
** EPITECH PROJECT, 2018
** my_revstr
** File description:
** Reverses a string
*/

char *my_revstr(char *str)
{
    int i = 0;
    int j = 0;
    int temp = 0;

    while (str[j] != '\0')
        j++;
    j--;
    while (i < j) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
    return (str);
}
