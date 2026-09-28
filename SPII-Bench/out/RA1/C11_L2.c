/* ------------------------------------------------------------
 * Programming Fundamentals - Lab exercise
 * Task: Algorithm #22 - Bubble Sort
 * ------------------------------------------------------------ */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int size;
    scanf("%d", &size);
    int arr[size];
    for (int i = 0; i < size; i++) scanf("%d", &arr[i]);

    // classic bubble sort, swapping adjacent out-of-order pairs
    for (int i = 0; i < size - 1; i++)
        for (int j = 0; j < size - 1 - i; j++)
            if (arr[j] > arr[j + 1]) { int tmp = arr[j]; arr[j] = arr[j + 1]; arr[j + 1] = tmp; }

    for (int i = 0; i < size; i++) { printf("%d", arr[i]); if (i < size - 1) printf(" "); }
    printf("\n");

    return 0;
}
