/*
** EPITECH PROJECT, 2018
** my_strlen
** File description:
** Counts and returns the number of characters found in the string passed as parameter
*/

int my_strlen(char const *str)
{
    int length = 0;

    while(str[length]) {
	    length++;
    }

    return (length);
}
