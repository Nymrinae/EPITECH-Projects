/*
** EPITECH PROJECT, 2018
** strncmp
** File description:
** strncmp
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;

    for (; s1[i] != '\0' && s1[i] == s2[i] && i < n - 1; i++);
    return (s1[i] - s2[i]);
}
