/*
** EPITECH PROJECT, 2018
** sort in array
** File description:
** sort int array (shell sort)
*/

static void insertion_sort(int i, int half, int *array)
{
    int j = i;
    int current = array[i];

    for (; j >= half && array[j - half] > current; j -= half)
        array[j] = array[j - half];
    array[j] = current;
}

void my_sort_int_array(int *array, int size)
{
    int i;
    int half = size / 2;

    for (; half > 0; half /= 2) {
        for (i = half; i < size; i++)
            insertion_sort(i, half, array);
    }
}
