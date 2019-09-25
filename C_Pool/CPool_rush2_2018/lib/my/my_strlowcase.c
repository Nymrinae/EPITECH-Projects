/*
** EPITECH PROJECT, 2018
** strlowcase
** File description:
** strlowcase
*/

char *my_strlowcase(char *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 'a' - 'A';
    }
    return (str);
}
