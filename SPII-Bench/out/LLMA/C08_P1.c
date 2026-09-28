#include <stdio.h>

int main(void) {
    int n;
    scanf("%d", &n);
    int a[n];
    for (int k = 0; k < n; k++) scanf("%d", &a[k]);
    int key;
    scanf("%d", &key);

    int left = 0, right = n - 1, found = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (a[mid] == key) { found = mid; break; }
        if (a[mid] < key) left = mid + 1;
        else right = mid - 1;
    }

    if (found >= 0) printf("Found at index %d\n", found);
    else printf("Not found\n");
    return 0;
}
