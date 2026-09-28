// binary search in a sorted array
#include <stdio.h>

int search(int a[], int lo, int hi, int x)
{
    if (lo > hi)
        return -1;
    int mid = (lo + hi) / 2;
    if (a[mid] == x)
        return mid;
    if (x < a[mid])
        return search(a, lo, mid - 1, x);
    return search(a, mid + 1, hi, x);
}

int main(void)
{
    int n, i, x;
    int a[1000];

    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    scanf("%d", &x);

    int result = search(a, 0, n - 1, x);
    if (result == -1)
        printf("Not found\n");
    else
        printf("Found at index %d\n", result);

    return 0;
}
