#include <criterion/criterion.h>

char *my_strcmp(char const *s1, char const *s2);

Test(my_strcmp, return_value_if_equal)
{
    char *str1 = "Test";
    char *str2 = "Test"
    cr_assert__eq(my_strcmp(str1, str2), 1);
}
