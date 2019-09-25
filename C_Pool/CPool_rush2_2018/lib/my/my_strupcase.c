/*
** EPITECH PROJECT, 2018
** strupcase
** File description:
** strupcase
*/

char *my_strupcase(char *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] += 'A' - 'a';
    }
    return (str);
}
