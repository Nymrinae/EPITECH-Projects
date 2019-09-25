/*
** EPITECH PROJECT, 2018
** test_my_revstr
** File description:
** Testing my_revstr purposes
*/

#include <criterion/criterion.h>

char *my_revstr(char *str);

Test(my_revstr, return_value_if_reversed)
{
    char str[6] = {0};

    strcpy(str, "Hello");
    cr_assert_str_eq(my_revstr(str), "olleH");
}
