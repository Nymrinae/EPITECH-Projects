/*
** EPITECH PROJECT, 2018
** my_str_islower
** File description:
** Return 1 || 0 if the string passed as parameter only contains lc alpha char or not
*/

int my_str_islower(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
	    if (str[i] < 'a' || str[i] > 'z')
	        return (0);
	    i++;	
    }
    return (1);
}
