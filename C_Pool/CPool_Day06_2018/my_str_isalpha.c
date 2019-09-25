/*
** EPITECH PROJECT, 2018
** my_str_isalpha
** File description:
** Returns either 1 || 0 if the string passed as parameter contains only alpha chars
*/

int my_str_isalpha(char const *str)
{
    int i = 0;
    
    while (str[i] != '\0') {
	if ((str[i] < 'A') || (str[i] > 'Z' && str[i] < 'a') || str[i] > 'z')
	    return (0);
	i++;
    }
    return (1);
}
