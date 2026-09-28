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
    int n, i, k, lo, hi, mid, res = -1;
    int a[10000];
    scanf("%d", &n);
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    scanf("%d", &k);
    lo = 0;
    hi = n - 1;
    while (lo <= hi) {
        mid = (lo + hi) / 2;
        if (a[mid] == k) {
            res = mid;
            break;
        } else if (a[mid] < k) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    if (res >= 0) printf("Found at index %d\n", res);
    else printf("Not found\n");

    return 0;
}
