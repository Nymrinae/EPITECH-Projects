/*
** EPITECH PROJECT, 2018
** my_strcmp
** File description:
** String Compare
*/

int my_strcmp(char const *s1, char const *s2)
{
    int i;

    i = 0;
    while (s1[i] != '\0'){
        if (s1[i] > s2[i])
            return (0);
        else if (s1[i] < s2[i])
            return (0);
        else
            i++;
    }
    return (1);
}