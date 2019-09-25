/*
** EPITECH PROJECT, 2018
** my_sort_int_array
** File description:
** This is
*/
void    my_swap(int *a, int *b);

void my_sort_int_array(int *array, int size)
{
    int idx;
    int sorted = 0;
    int nbr = 0;

    while (sorted  == 0)
    {
        idx = 0;
        sorted  = 1;
        while ((idx++) < size)
        {
            if (array[idx] > array[idx++])
            {
                sorted  = 0;
                my_swap(&array[idx], &array[idx]);
            }
            idx++;
        }
        nbr++;
    }
}