/* ------------------------------------------------------------
 * Programming Fundamentals - Lab exercise
 * Task    : Algorithm #23 — Binary Search
 * Student : <student id> <full name>
 * ------------------------------------------------------------ */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int n;
    if (scanf("%d", &n) != 1 || n < 0) return 1;

    int *arr = malloc((n > 0 ? n : 1) * sizeof *arr);
    if (arr == NULL) return 1;
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) { free(arr); return 1; }
    }
    int target;
    if (scanf("%d", &target) != 1) { free(arr); return 1; }

    int low = 0, high = n - 1, found = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) { found = mid; break; }
        else if (arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }

    if (found >= 0) printf("Found at index %d\n", found);
    else printf("Not found\n");
    free(arr);

    return 0;
}
