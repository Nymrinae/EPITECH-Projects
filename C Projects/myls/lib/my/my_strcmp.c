/*
** EPITECH PROJECT, 2018
** my_strcmp
** File description:
** This function reproduce the
** behavior of the strcmp
*/

int    my_strcmp(char const *s1, const char *s2)
{
    int i = 0;

    while (s1[i] && s2[i]){
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
        i++;
    }

    return (s1[i] - s2[i]);
}