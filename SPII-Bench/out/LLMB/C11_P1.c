/* ------------------------------------------------------------
 * Programming Fundamentals - Lab exercise
 * Student : <student id> <full name>
 * ------------------------------------------------------------ */
#include <stdio.h>

static void swap(int *x, int *y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

static void bubble_sort(int *arr, int size)
{
    for (int pass = 0; pass < size - 1; pass++)
        for (int k = 0; k + 1 < size - pass; k++)
            if (arr[k] > arr[k + 1])
                swap(&arr[k], &arr[k + 1]);
}

int main(void)
{
    int size;
    if (scanf("%d", &size) != 1) return 0;
    int arr[size];
    for (int k = 0; k < size; k++) scanf("%d", &arr[k]);

    bubble_sort(arr, size);

    for (int k = 0; k < size; k++)
        printf(k == 0 ? "%d" : " %d", arr[k]);
    putchar('\n');
    return 0;
}
