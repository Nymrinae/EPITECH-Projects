/*                                                                              
** EPITECH PROJECT, 2018                                                       
** test_my_strncpy                                                             
** File description:                                                           
** Testing my_strncpy purposes                                                 
*/

#include <criterion/criterion.h>

int my_str_islower(char const *str);

Test(my_str_islower, all_chars_are_lc)
{
    char dest[] = "martin";
    
    cr_assert_eq(my_str_islower(dest) , 1);
}

Test(my_str_islower, some_chars_are_uc)
{
    char dest[] = "MaRtin";

    cr_assert_eq(my_str_islower(dest), 0);
}

Test(my_str_is_lower, some_fucking_non_alpha_chars)
{
    char dest[] = "ma~i9";

    cr_assert_eq(my_str_islower(dest), 0);
}
