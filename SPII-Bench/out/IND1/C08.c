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
    scanf("%d", &n);

    // Read the sorted array
    int arr[100];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Read the target value
    int target;
    scanf("%d", &target);

    // Binary search
    int left = 0;
    int right = n - 1;
    int found = 0;
    int index = -1;

    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == target) {
            found = 1;
            index = mid;
            break;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    if (found) {
        printf("Found at index %d\n", index);
    } else {
        printf("Not found\n");
    }

    return 0;
}
