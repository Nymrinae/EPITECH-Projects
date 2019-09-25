/*
** EPITECH PROJECT, 2018
** my_str_islower
** File description:
** htfgbthrtger
*/

int my_str_islower(char const *str)
{
    int i = 0;

    while (str[i]) {
        if (str[i] < 'a' || str[i] > 'z')
            return (0);
        i++;	
    }
    return (1);
}
