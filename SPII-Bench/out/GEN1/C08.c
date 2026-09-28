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
    int n, x;
        scanf("%d", &n);
        int arr[1000];
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }
        scanf("%d", &x);
    
        int left = 0, right = n - 1;
        int found = -1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (arr[mid] == x) {
                found = mid;
                break;
            } else if (arr[mid] < x) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        if (found != -1) {
            printf("Found at index %d\n", found);
        } else {
            printf("Not found\n");
        }


    return 0;
}
