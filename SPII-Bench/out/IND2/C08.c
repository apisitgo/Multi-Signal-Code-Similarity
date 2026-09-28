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
    printf("Enter n: ");
    scanf("%d", &n);

    int numbers[1000];
    int i = 0;
    while (i < n) {
        scanf("%d", &numbers[i]);
        i = i + 1;
    }

    int target;
    printf("Enter value to search: ");
    scanf("%d", &target);

    int low = 0;
    int high = n - 1;
    int found_index = -1;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (numbers[mid] == target) {
            found_index = mid;
            break;
        } else if (numbers[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    if (found_index != -1) {
        printf("Found at index %d\n", found_index);
    } else {
        printf("Not found\n");
    }

    return 0;
}
