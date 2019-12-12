/*
** EPITECH PROJECT, 2018
** parse_names
** File description:
** parsing "name"
*/

#include "mysh.h"

void parse_hostname(char *hostname)
{
    for (int i = 9; hostname[i] != '.'; i++)
        my_putchar(hostname[i]);
}

void parse_username(char *username)
{
    for (int i = 5; username[i] != '\0'; i++)
        my_putchar(username[i]);
}

void parse_file_name(char *str)
{
    int cursor = 0;
    int i = 0;
    int k = 0;

    for (i = 0; str[i]; i++)
        if (str[i] == '/')
            cursor = i + 1;

    if (str[cursor] != '\0') {
        for (int j = cursor; str[j]; j++)
            my_putchar(str[j]);
    } else {
        for (k = (cursor - 2); str[k] != '/'; k--)
            i = k;
        for (k = k+1; str[k] != '/'; k++)
            my_putchar(str[k]);
    }
}

char *parse_pathname(char *s1, char *s2)
{
    int i = 0;
    int count = 0;
    char *tmp;
    int k = 0;

    count = parse_space_and_tab(s1, count);
    for (i = count; ((s1[i] >= 'a' && s1[i] <= 'z') ||
    (s1[i] >= 'A' && s1[i] <= 'Z') || (s1[i] == '/')); i++) {
        s2[i] = s1[i];
    }
    s2[i] = '\0';

    if (s2[0] == '\0') {
        tmp = next_parse_pathname(tmp, s2, k, count);
        return (tmp);
    }
    return (s2);
}

char *next_parse_pathname(char *tmp, char *s2, int k, int count)
{
    tmp = malloc(sizeof(char) * my_strlen(s2) + 1);
    for (int j = count; s2[j] != '\0'; j++) {
        tmp[k] = s2[j];
        k++;
    }
    tmp[k] = '\0';
    return (tmp);
}
