/*
    Programming Fundamentals - Lab exercise
    Task    : Algorithm #23 - Binary Search
    Student : <student id> <full name>
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    // read array
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    // read value to look for
    int target;
    scanf("%d", &target);

    // standard binary search on a sorted array
    int lo = 0, hi = n - 1, idx = -1;
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if (a[mid] == target)
        {
            idx = mid;
            break;
        }
        else if (a[mid] < target)
            lo = mid + 1;
        else
            hi = mid - 1;
    }

    if (idx >= 0)
        printf("Found at index %d\n", idx);
    else
        printf("Not found\n");
    return 0;
}
