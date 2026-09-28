/* ------------------------------------------------------------
 * Programming Fundamentals - Lab exercise
 * Task: Algorithm #23 - Binary Search
 * ------------------------------------------------------------ */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* recursive binary search instead of the iterative loop */
static int binarySearchRec(const int *arr, int left, int right, int key)
{
    if (left > right) return -1;

    int mid = left + (right - left) / 2;
    if (arr[mid] == key) return mid;
    if (arr[mid] > key) return binarySearchRec(arr, left, mid - 1, key);
    return binarySearchRec(arr, mid + 1, right, key);
}

int main(void)
{
    int size;
    scanf("%d", &size);
    int arr[size];
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    int key;
    scanf("%d", &key);

    int foundIdx = binarySearchRec(arr, 0, size - 1, key);
    if (foundIdx < 0) {
        printf("Not found\n");
        return 0;
    }
    printf("Found at index %d\n", foundIdx);
    return 0;
}
