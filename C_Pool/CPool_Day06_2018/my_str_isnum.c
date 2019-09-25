/*
** EPITECH PROJECT, 2018
** my_str_isnum
** File description:
** Returns either 1 || 0 if the string passed as parameter contains only digits or not
**
*/

int my_str_isnum(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
	if (str[i] < '0' || str[i] > '9')
	    return (0);
	i++;
    }
    return (1);
}
