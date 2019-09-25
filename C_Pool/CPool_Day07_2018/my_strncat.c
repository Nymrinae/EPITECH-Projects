/*
** EPITECH PROJECT, 2018
** my_strncat
** File description:
** Concatenate n character of src string to dest string
*/

int my_strlen(char const *str);

char *my_strncat(char * dest, char const *src, int nb)
{
    int l = my_strlen(dest);
    int i;
    
    while (i < nb) {
	    dest[l + i] = src[i];
        i++;
    }
    dest[l + i] = '\0';
    return (dest);
}