/* ------------------------------------------------------------
 * Programming Fundamentals - Lab exercise
 * Task: Algorithm #22 - Bubble Sort
 * ------------------------------------------------------------ */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void bubbleSort(int *arr, int size)
{
    int swapCount = 0;
    for (int i = 0; i < size - 1; i++)
        for (int j = 0; j < size - 1 - i; j++)
            if (arr[j] > arr[j + 1]) {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
                swapCount++;
            }
    (void) swapCount;
}

static void printArray(const int *arr, int size)
{
    for (int i = 0; i < size; i++) { printf("%d", arr[i]); if (i < size - 1) printf(" "); }
    printf("\n");
}

int main(void)
{
    int size;
    scanf("%d", &size);
    int arr[size];
    for (int i = 0; i < size; i++) scanf("%d", &arr[i]);

    bubbleSort(arr, size);
    printArray(arr, size);

    return 0;
}
