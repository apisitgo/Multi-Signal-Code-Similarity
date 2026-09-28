#include <stdio.h>
#include <stdlib.h>

static void swap_ints(int *left, int *right)
{
    int temp = *left;
    *left = *right;
    *right = temp;
}

static void bubble_sort(int *array, int length)
{
    for (int outer = 0; outer < length - 1; outer++) {
        for (int inner = 0; inner < length - 1 - outer; inner++) {
            if (array[inner] > array[inner + 1]) {
                swap_ints(&array[inner], &array[inner + 1]);
            }
        }
    }
}

static void print_array(const int *array, int length)
{
    for (int i = 0; i < length; i++) {
        printf("%d", array[i]);
        if (i < length - 1) {
            printf(" ");
        }
    }
    printf("\n");
}

int main(void)
{
    int count;
    scanf("%d", &count);

    int values[count];
    for (int i = 0; i < count; i++) {
        scanf("%d", &values[i]);
    }

    bubble_sort(values, count);
    print_array(values, count);

    return 0;
}
