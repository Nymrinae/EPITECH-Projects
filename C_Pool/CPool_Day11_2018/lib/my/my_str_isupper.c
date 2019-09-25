/*
** EPITECH PROJECT, 2018
** my_str_isupper
** File description:
** Return 1 || 0 if the string passed as parameter only contains uc alpha char or not
*/

int my_str_isupper(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] < 'A' || str[i] > 'Z')
            return (0);
        i++;	
    }
    return (1);
}
