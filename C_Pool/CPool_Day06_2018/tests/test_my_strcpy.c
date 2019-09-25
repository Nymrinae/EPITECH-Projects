/*
** EPITECH PROJECT, 2018
** Test my_strcpy
** File description:
** Testing strcpy purposes
*/

#include <criterion/criterion.h>

char *my_strcpy(char *dest, char const *src);

Test(my_strcpy, copy_string_in_empty_array)
{
    char dest[30] = {0};

    my_strcpy(dest, "Hello");
    cr_assert_str_eq(dest, "Hello");
}

Test(my_strcpy, copy_string_in_empty_array_return_value)
{
    char dest[30] = {0};
    char *copy = my_strcpy(dest, "Hello");

    cr_assert_str_eq(copy, "Hello");
}
