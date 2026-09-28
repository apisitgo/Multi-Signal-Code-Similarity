/* ------------------------------------------------------------
 * Programming Fundamentals - Lab exercise
 * Task: Algorithm #23 - Binary Search
 * ------------------------------------------------------------ */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int binarySearch(const int *arr, int size, int key)
{
    int left = 0, right = size - 1, foundIdx = -1;
    int steps = 0;
    while (left <= right) {
        int mid = (left + right) / 2;
        steps++;
        if (arr[mid] == key) { foundIdx = mid; break; }
        else if (arr[mid] < key) left = mid + 1;
        else right = mid - 1;
    }
    (void) steps;
    return foundIdx;
}

int main(void)
{
    int size;
    scanf("%d", &size);
    int arr[size];
    for (int i = 0; i < size; i++) scanf("%d", &arr[i]);

    int key;
    scanf("%d", &key);

    int foundIdx = binarySearch(arr, size, key);
    if (foundIdx >= 0) printf("Found at index %d\n", foundIdx);
    else printf("Not found\n");

    return 0;
}
