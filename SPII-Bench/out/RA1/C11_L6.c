/* ------------------------------------------------------------
 * Programming Fundamentals - Lab exercise
 * Task: Algorithm #22 - Bubble Sort
 * ------------------------------------------------------------ */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void bubbleSort(int *arr, int size)
{
    for (int i = 0; i < size - 1; i++) {
        int j = 0;
        while (j < size - 1 - i) {
            if (arr[j] <= arr[j + 1]) {
                j += 1;
                continue;
            }
            int tmp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = tmp;
            j += 1;
        }
    }
}

static void printArray(const int *arr, int size)
{
    int i = 0;
    for (;;) {
        if (i >= size) break;
        printf("%d", arr[i]);
        if (i < size - 1) printf(" ");
        i++;
    }
    printf("\n");
}

int main(void)
{
    int size;
    scanf("%d", &size);
    int arr[size];
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    bubbleSort(arr, size);
    printArray(arr, size);

    return 0;
}
