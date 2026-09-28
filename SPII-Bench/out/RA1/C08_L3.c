/* ------------------------------------------------------------
 * Programming Fundamentals - Lab exercise
 * Task: Algorithm #23 - Binary Search
 * ------------------------------------------------------------ */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int size;
    int key;
    int left, right, foundIdx;
    int steps = 0;      // redundant counter

    scanf("%d", &size);
    int arr[size];
    for (int i = 0; i < size; i++) scanf("%d", &arr[i]);
    scanf("%d", &key);

    left = 0;
    right = size - 1;
    foundIdx = -1;
    while (left <= right) {
        int mid = (left + right) / 2;
        steps++;
        if (arr[mid] == key) { foundIdx = mid; break; }
        else if (arr[mid] < key) left = mid + 1;
        else right = mid - 1;
    }

    (void) steps;
    if (foundIdx >= 0) printf("Found at index %d\n", foundIdx);
    else printf("Not found\n");

    return 0;
}
