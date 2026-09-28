/* ------------------------------------------------------------
 * Programming Fundamentals - Lab exercise
 * Task    : Algorithm #23 — Binary Search
 * Student : <student id> <full name>
 * ------------------------------------------------------------ */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int bsearch_i(const int *a, int n, int key)
{
    int lo = 0, hi = n - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (a[mid] == key) return mid;
        if (a[mid] < key) lo = mid + 1;
        else hi = mid - 1;
    }
    return -1;
}

int main(void)
{
    int n, key;
    if (scanf("%d", &n) != 1 || n < 0) return 0;
    int *a = malloc(sizeof(int) * (n > 0 ? n : 1));
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    if (scanf("%d", &key) != 1) { free(a); return 0; }
    int idx = bsearch_i(a, n, key);
    if (idx >= 0) printf("Found at index %d\n", idx);
    else printf("Not found\n");
    free(a);
    return 0;
}
