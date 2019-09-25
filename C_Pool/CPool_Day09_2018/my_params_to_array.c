/*
** EPITECH PROJECT, 2018
** my_params_to_array
** File description:
** Stores the programs parameters into an array of structures
*/

#include "stdlib.h"
#include "include/struct.h"
#include "include/my.h"

struct info_param *my_params_to_array(int ac, char **av);

struct info_param *array;

array = malloc(sizeof(struct info_param));
if (array == NULL) {
    return (NULL);
}
return (array);