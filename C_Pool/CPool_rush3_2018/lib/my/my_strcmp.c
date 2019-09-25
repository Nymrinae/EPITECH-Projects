/*
** EPITECH PROJECT, 2018
** my_strcmp
** File description:
** This function reproduce the
** behavior of the strcmp
*/

int    my_strlen(const char *str);

int    my_strcmp(char const *s1, const char *s2)
{
    int	idx = 0;

    if (my_strlen(s1) < my_strlen(s2))
        return (-1);
    if (my_strlen(s1) > my_strlen(s2))
        return (1);

    while (s1[idx] && s2[idx] && s1[idx] == s2[idx])
        idx++;
    return (s1[idx] - s2[idx]);
}